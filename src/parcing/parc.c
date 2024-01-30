/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/30 12:09:51 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


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
	return (l);
}

void	*to_structC(char **str)
{
	t_camera	ligh;
	t_camera	*l;
	int			i;
	char		**split_str_1;
	char		**split_str_2;

	initC(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 4)
		error(1); 
	l->fov = ft_atoi(str[3]);
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	i = -1;
	while(++i < 3)
	{
		l->xyz[i] = ft_atoi(split_str_1[i]);
		l->norm_vec[i] = ft_atoi(split_str_2[i]);
	}
	return (l);
}

void	*to_structL(char **str)
{
	t_light	ligh;
	t_light	*l;
	int			i;
	char		**split_str_1;
	char		**split_str_3;

	initL(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 4)
		error(1); 
	l->ratio = ft_atof(str[2]);
	split_str_1 = ft_split(str[1], ',');
	split_str_3 = ft_split(str[3], ',');
	i = -1;
	while(++i < 3)
	{
		l->xyz[i] = ft_atoi(split_str_1[i]);
		l->rgb[i] = ft_atoi(split_str_3[i]);
	}
	return (l);
}

void	*to_struct_pl(char **str)
{
	t_plane	ligh;
	t_plane	*l;
	int			i;
	char		**split_str_1;
	char		**split_str_2;
	char		**split_str_3;

	init_pl(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 4)
		error(1); 
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	split_str_3 = ft_split(str[3], ',');
	i = -1;
	while(++i < 3)
	{
		l->xyz[i] = ft_atoi(split_str_1[i]);
		l->norm_vec[i] = ft_atoi(split_str_2[i]);
		l->rgb[i] = ft_atoi(split_str_3[i]);
	}
	return (l);
}

void	*to_struct_cy(char **str)
{
	t_cyl	ligh;
	t_cyl	*l;
	int			i;
	char		**split_str_1;
	char		**split_str_2;
	char		**split_str_5;

	init_cy(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 6)
		error(1); 
	l->diam = ft_atof(str[3]);
	l->heig = ft_atof(str[4]);
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	split_str_5 = ft_split(str[5], ',');
	i = -1;
	while(++i < 3)
	{
		l->xyz[i] = ft_atoi(split_str_1[i]);
		l->norm_vec[i] = ft_atoi(split_str_2[i]);
		l->rgb[i] = ft_atoi(split_str_5[i]);
	}
	return (l);
}

void	*to_struct_sp(char **str)
{
	t_sphere	ligh;
	t_sphere	*l;
	int			i;
	char		**split_str_1;
	char		**split_str_3;

	init_sp(&ligh);
	l = &ligh;
	i = -1;
	while(str && str[++i])
		;
	if (i != 4)
		error(1); 
	l->diametr = ft_atof(str[2]);
	split_str_1 = ft_split(str[1], ',');
	split_str_3 = ft_split(str[3], ',');
	i = -1;
	while(++i < 3)
	{
		l->rgb[i] = ft_atoi(split_str_1[i]);
		l->rgb[i] = ft_atoi(split_str_3[i]);
	}
	return (l);
}

void	id_check(char **id)
{
	void	*list;
	
	list = NULL;
	if (!ft_strcmp(id[0], "A"))
		(t_amlight *)list = to_structA(id);
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
	
	printf("%d", ((t_amlight *)list)->rgb[2]);
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
