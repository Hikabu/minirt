/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:51:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/25 18:28:50 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	id_check5(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "sp"))
	{
		if ((*ent)->sphere != NULL)
		{
			tmp = (*ent)->sphere;
			ft_lstadd_back_sphere(&((*ent)->sphere), to_struct_sp(str));
		}
		(*ent)->sphere = to_struct_sp(str);
		if (tmp)
			(*ent)->sphere = tmp;
	}
	else if (!ft_strncmp(str[0], "#", 1))
		return ;
	else
		error(1); ////izmenit
	printf("%d\n", (*ent)->sphere->rgb[2]);
	printf("is there any merge????\n");
}

void	id_check4(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "cy"))
	{
		if ((*ent)->cyl != NULL)
		{
			tmp = (*ent)->cyl;
			ft_lstadd_back_cyl(&((*ent)->cyl), to_struct_cy(str));
		}
		(*ent)->cyl = to_struct_cy(str);
		if (tmp)
			(*ent)->cyl = tmp;
	}
	else
		id_check5(str, ent);
}

void	id_check3(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "pl"))
	{
		if ((*ent)->plane != NULL)
		{
			tmp = (*ent)->plane;
			ft_lstadd_back_plane(&((*ent)->plane), to_struct_pl(str));
		}
		(*ent)->plane = to_struct_pl(str);
		if (tmp)
			(*ent)->plane = tmp;
	}
	else
		id_check4(str, ent);
}

void	id_check2(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "L"))
	{
		if ((*ent)->light != NULL)
		{
			tmp = (*ent)->light;
			ft_lstadd_back_light(&((*ent)->light), to_struct_l(str));
		}
		(*ent)->light = to_struct_l(str);
		if (tmp)
			(*ent)->light = tmp;
	}
	else
		id_check3(str, ent);
}

void	id_check1(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "C"))
	{
		if ((*ent)->camera != NULL)
		{
			tmp = (*ent)->camera;
			ft_lstadd_back_camera(&((*ent)->camera), to_struct_c(str));
		}
		(*ent)->camera = to_struct_c(str);
		if (tmp)
			(*ent)->camera = tmp;
	}
	else
		id_check2(str, ent);
}
