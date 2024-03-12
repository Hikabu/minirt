/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_camputing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:37:32 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/12 22:15:25 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_for_shadow(t_data *data, t_pixel *pixel)
{
	float	dist;
	t_ray	ray;
	t_crd	d;

	dist = -1;
	ray.point[0] = pixel->coor;
	scalar_multiplication(&ray.point[0], &ray.point[0], 
		-pixel->lenght * 0.995);
	vector_addition(&ray.point[0], &pixel->ray.point[0],
		&ray.point[0]);
	ray.point[1] = data->scene->obj->light->xyz;
	vector_subtraction(&d, &(ray.point[0]), &(ray.point[1]));
	if (check_for_shadow_sphere(data, &ray, &d))
		return (1);
	if (check_for_shadow_planes(data, &ray, &d))
		return (1);
	if (check_for_shadow_sphere(data, &ray, &d))
		return (1);
	return (0);
}

float	pixel_computing_plane_difreflect_ratio(t_data *data, t_pixel *pixel)
{
	t_crd	light_dir;
	t_crd	normal;
	float	light_intens;

	normal = pixel->plane->xyz;
	vector_subtraction(&light_dir, &data->scene->obj->light->xyz,
		&pixel->intersection);
	norm_vector(&light_dir);
	light_intens = ang_bet_2_vec(&light_dir, &normal)
		* data->scene->obj->light->ratio;
	if (light_intens > 0)
		return (light_intens);
	return (-light_intens);
}

void	pixel_computing_plane(t_data *data, t_pixel *pixel)
{
	int		light;
	float	light_ratio;

	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y,
		pixel->plane->color_ambient);
	if (!data->scene->obj->light || check_for_shadow(data, pixel))
		return ;
	light_ratio = pixel_computing_plane_difreflec_ratio(data, pixel); //eflection ratio is the amount of light that is reflected off the surface of the object 
	if (light_ratio <= 0)
		return ;
	light = color_diffusal(pixel->plane->color_ambient, pixel->plane->color, 
		data->scene->obj->light->rgb, light_ratio);
	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y, light);
	return ;		
}


void	pixel_computing(t_data *data, t_pixel *pixel)
{
	if (pixel->lenght <= 0
		|| (!pixel->plane && !pixel->sphere && !pixel->cyl))
	{
		mlx_pixel_put(data->mlx, data->window,
			pixel->x, pixel->y, BACKGROUND_COLOR);
		return ;
	}
	pixel->intersection = pixel->coor;
	scalar_multiplication(&pixel->intersection, &pixel->intersection, 
		-pixel->lenght);
	vector_addition(&pixel->intersection, &pixel->ray.point[0], 
		&pixel->intersection);
	if (pixel->plane)
		pixel_plane_computing(data, pixel);
	else if (pixel->sphere)
		pixel_computing_sphere(data, pixel);
	else if (pixel->cyl)
		pixel_computing_cylinder(data, pixel);
		
}
