// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/19 23:23:02 by valeriafedo       #+#    #+#             */
// /*   Updated: 2024/01/19 23:25:18 by valeriafedo      ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minirt.h"


void	init_colo(t_color *list)
{
	list->b = 0;
	list->r = 0;
	list->g = 0;
}

// void	init_light(t_light *list)
// {
// 	list->ratio = 0;
// 	list->id = 0;
// 	list->rgb.b = 0;
// 	list->rgb.r = 0;
// 	list->rgb.g = 0;
// 	list->xyz.x = 0;
// 	list->xyz.y = 0;
// 	list->xyz.z = 0;
// }
void	init_c(t_camera *list)
{
	list->id = 0;
	list->xyz.x = 0;
	list->xyz.y = 0;
	list->xyz.z = 0;
	list->norm_vec.x = 0;
	list->norm_vec.y = 0;
	list->norm_vec.z = 0;
	list->fov = 0;
	list->origin->x = 0;
	list->origin->y = 0;
	list->origin->z = 0;
	list->direction->x = 0;
	list->direction->y = 0;
	list->direction->z = 0;
	list->crd->x = 0;
	list->crd->y = 0;
	list->crd->z = 0;
}

void	init_a(t_amlight *list)
{
	list->ratio = 0;
	list->id = 0;
	list->rgb.b = 0;
	list->rgb.r = 0;
	list->rgb.g = 0;
}



void	init_l(t_light *list)
{
	list->id = 0;
	list->xyz.x = 0;
	list->xyz.y = 0;
	list->xyz.z = 0;
	list->ratio = 0;
	list->rgb.r = 0;
	list->rgb.g = 0;
	list->rgb.b = 0;
}

void	init_pl(t_plane *list)
{
	list->id = 0;
	list->point.x = 0;
	list->point.y = 0;
	list->point.z = 0;
	list->xyz.x = 0;
	list->xyz.y = 0;
	list->xyz.z = 0;
	list->norm_vec.x = 0;
	list->norm_vec.y = 0;
	list->norm_vec.z = 0;
	list->rgb.r = 0;
	list->rgb.g = 0;
	list->rgb.b = 0;
	list->color = 0;
	list->color_ambient = 0;
	list->next = NULL;
}

void	init_cy(t_cyl *list)
{
	list->id = 0;
	list->point.x = 0;
	list->point.y = 0;
	list->point.z = 0;
	list->xyz.x = 0;
	list->xyz.y = 0;
	list->xyz.z = 0;
	list->norm_vec.x = 0;
	list->norm_vec.y = 0;
	list->norm_vec.z = 0;
	list->diam = 0;
	list->heig = 0;
	list->rgb.r = 0;
	list->rgb.g = 0;
	list->rgb.b = 0;
	list->color = 0;
	list->color_ambient = 0;
	list->next = NULL;
}
void	init_sphere(t_sphere *list)
{
	list->id = 0;
	list->point.x = 0;
	list->point.y = 0;
	list->point.z = 0;
	list->xyz.x = 0;
	list->xyz.y = 0;
	list->xyz.z = 0;
	// list->norm_vec.x = 0;
	// list->norm_vec.y = 0;
	// list->norm_vec.z = 0;
	list->diametr = 0;
	// list->heig = 0;
	list->rgb.r = 0;
	list->rgb.g = 0;
	list->rgb.b = 0;
	// list->color = 0;
	list->color_ambient = 0;
	list->next = NULL;
}
void	init_ent(t_entire *ent)
{
	ent->amlight = NULL;
	ent->camera = NULL;
	ent->scene = NULL;
	ent->light = NULL;
	ent->plane = NULL;
	ent->cyl = NULL;
	ent->sphere = NULL;
	ent->crd = NULL;
	ent->col = NULL;
}

void	init_all(t_entire *ent)
{
	init_colo(ent->col);
	init_l(ent->light);
	init_a(ent->amlight);
	init_c(ent->camera);
	init_sphere(ent->sphere);
	init_cy(ent->cyl);
	init_pl(ent->plane);

}