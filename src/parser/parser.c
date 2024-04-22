/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:16 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:40:05 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return ((int) c);
	return (0);
}

static	int	open_file(int argc, char **argv)
{
	char	*tmp;
	int		i;

	if (argc != 2 || !argv[1] || !argv[1][0] || ft_strlen (argv[1]) < 3)
	{
		printf("Error\n");
		exit (2);
	}
	tmp = argv[1];
	i = 0;
	while (tmp[i])
		i++;
	tmp = tmp + i - 3;
	if (ft_strncmp(tmp, ".rt", 4))
	{
		printf("Error\n");
		exit (2);
	}
	i = open (argv[1], O_RDONLY);
	if (!i || i == -1)
	{
		printf("Cannot open the \"%s\" file\n", argv[1]);
		exit(2);
	}
	return (i);
}

static void	parser_linehandler(t_parser	*p)
{
	p->i = 0;
	parser_skipspaces(p->str, &(p->i));
	if (!p->str || !p->str[p->i] || p->str[p->i] == '#')
		return ;
	else if (p->str[p->i] == 'A' && ft_isspace(p->str[p->i + 1]))
		parser_readambient(p);
	else if (p->str[p->i] == 'C' && ft_isspace(p->str[p->i + 1]))
		parser_readcamera(p);
	else if (p->str[p->i] == 'L' && ft_isspace(p->str[p->i + 1]))
		parser_readlight(p);
	else if (!ft_strncmp(p->str + p->i, "sp", 2) && ft_isspace(p->str[p->i + 2]))
		parser_readsphere(p);
	else if (!ft_strncmp(p->str + p->i, "pl", 2) && ft_isspace(p->str[p->i + 2]))
		parser_readplane(p);
	else if (!ft_strncmp(p->str + p->i, "cy", 2) && ft_isspace(p->str[p->i + 2]))
		parser_readcylinder(p);
	else
		parser_error(1, p);
}

t_scene	*parser(int argc, char **argv)
{
	t_parser	parser_env;

	parser_env.file_fd = open_file(argc, argv);
	parser_env.scene = parser_createscene(&parser_env);
	parser_env.str = get_next_line(parser_env.file_fd);
	while (parser_env.str)
	{
		parser_linehandler(&parser_env);
		free (parser_env.str);
		parser_env.str = get_next_line(parser_env.file_fd);
	}
	close(parser_env.file_fd);
	get_fov_angles(parser_env.scene);
	parser_env.scene->camera_point.z ++;
	translate_objects(parser_env.scene, &parser_env.scene->camera_point);
	rotate_objects(parser_env.scene, &parser_env.scene->camera_orientation);
	parser_fill_color_ambient(&parser_env);
	return (parser_env.scene);
}
