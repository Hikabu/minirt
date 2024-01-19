/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:23:02 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/19 23:25:18 by valeriafedo      ###   ########.fr       */
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
