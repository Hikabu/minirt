/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sp_cyl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:45:36 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/13 22:49:49 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	pixel_comp_sphere_refl_ratio(t_data *data, t_pixel *pixel)
{
	t_crd	light_dir;
	t_crd	normal;
	float	light_intens;

	vector_subtraction(&normal, &pixel->intersection, &pixel->sphere->xyz);
	norm_vector(&normal);
	vector_subtraction(&light_dir, &data->scene->obj->light->xyz,
		&pixel->intersection);
	norm_vector(&light_dir);
	light_intens = ang_bet_2_vec(&light_dir, &normal) 
		* data->scene->obj->light->ratio; // ratio_light??
	if (light_intens > 0)
		return (light_intens);
	return (0);
}
void pixel_computing_sphere(t_data *data, t_pixel *pixel)
{
	int		light;
	float	light_ratio;

	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y, pixel->sphere->color_ambient);
	if (!data->scene->obj->light || check_for_shadow(data, pixel))
		return ;
	light_ratio = pixel_comp_sphere_refl_ratio(data, pixel);
	if (light_ratio <= 0)
		return ;
	light = color_diffusual(pixel->sphere->color_ambient, pixel->sphere->color,
		data->scene->obj->light->color, light_ratio);
	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y, light);
	return ;
}

void	pixel_computing_cyl(t_data *data, t_pixel *pixel)
{
	int		light;
	float	light_ratio;

	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y,
		pixel->cyl->color_ambient);
	if (!data->scene->obj->light || check_for_shadow(data, pixel))
		return ;
	light_ratio = pixel_comp_cyl_refl_ratio(data, pixel);
	if (light_ratio <= 0)
		return ;
	light = color_diffusal(pixel->cyl->color_ambient, 
			pixel->cyl->color, data->scene->obj->light->color, 
			light_ratio);
	ft_mlx_pixel_put_img(&data->img, pixel->x, pixel->y, light);
	return ;
}
