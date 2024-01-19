/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/19 22:10:33 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initA(t_amlight *list)
{
	list->id = 1;
	list->ratio = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	initC(t_camera *list)
{
	list->id = 2;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->norm_vec[0] = 0;
	list->norm_vec[1] = 0;
	list->norm_vec[2] = 0;
	list->fov = 0;
	list->next = NULL;
}

void	initL(t_light *list)
{
	list->id = 3;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->ratio = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	init_pl(t_plane *list)
{
	list->id = 4;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->norm_vec[0] = 0;
	list->norm_vec[1] = 0;
	list->norm_vec[2] = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	init_cy(t_cyl *list)
{
	list->id = 5;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->norm_vec[0] = 0;
	list->norm_vec[1] = 0;
	list->norm_vec[2] = 0;
	list->diam = 0;
	list->heig = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	init_sp(t_sphere *list)
{
	list->id = 6;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->diametr = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	*to_structA(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	initA(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 3)
		error(1); 
	l->ratio = ft_atof(str[1]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	*to_structC(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	initC(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 4)
		error(1); 
	l->ratio = ft_atoi(str[3]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	*to_structL(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	initL(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 3)
		error(1); 
	l->ratio = ft_atof(str[0]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	*to_struct_pl(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	init_pl(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 3)
		error(1); 
	l->ratio = ft_atof(str[0]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	*to_struct_cy(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	init_cy(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 3)
		error(1); 
	l->ratio = ft_atof(str[0]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	*to_struct_sp(char **str)
{
	t_amlight	ligh;
	t_amlight	*l;
	int			i;
	char		**split_str_2;

	init_sp(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 3)
		error(1); 
	l->ratio = ft_atof(str[0]);
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
		l->rgb[i] = ft_atoi(split_str_2[i]);
}

void	id_check(char **id)
{
	void	*list;
	
	list = NULL;
	if (!ft_strcmp(id[0], "A"))
		list = to_structA(id);
	else if (!ft_strcmp(id[0], "C"))
		list = to_structC(id);
	else if (!ft_strcmp(id[0], "L"))
		list = to_structL(id);
	else if (!ft_strcmp(id[0], "pl"))
		list = to_struct_pl(id);
	else if (!ft_strcmp(id[0], "cy"))
		list = to_struct_cy(id);
	else if (!ft_strcmp(id[0], "sp"))
		list = to_struct_sp(id);
	else if (!ft_strncmp(id[0], "#", 1))
		return ;
	else
		error(1); ////izmenit
}

int	parc(char *line)
{
	int		i;
	char	**str;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
	str = ft_split(line, ' ');
	id_check(str);
	return 0;
}
