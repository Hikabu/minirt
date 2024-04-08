/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sp_cyl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:45:36 by vfedorov          #+#    #+#             */
/*   Updated: 2024/04/08 21:15:42 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_crd	norm_cyl(t_pixel *pixel);

int	color_diffusal(int color_sum, int col1, int col2, float intens) // blend two colors together with a specified intensity
{
	int	res;
	int	tmp;

	intens /= (float) 255;
	tmp = (color_sum >> 16 & 0xff)
		+ (int)(intens * ((float) (col1 >> 16 & 255)
			*((float)(col2 >> 16 & 255))));
	if (tmp > 255)
		res = 0xff0000;
	else
		res = tmp << 16;
	tmp = (color_sum >> 8 & 0xff)
			+ (int)(intens * ((float)(col1 >> 8 & 255)
				*((float)(col2 >> 8 & 255))));
	if (tmp > 255)
		res |= 0xff00;														//to extract and combine the individual color components
	else
		res |= tmp << 8;
	tmp = (color_sum & 0xff)
		+ (int)(intens * (((float)(col1 & 255) *((float)(col2 & 255)))));
	if (tmp > 255)
		res |= 0xff;
	else
		res |= tmp;
	return (res);
				
}

float	pixel_comp_sphere_refl_ratio(t_entire *data, t_pixel *pixel)
{
	t_crd	light_dir;
	t_crd	normal;
	float	light_intens;

	vector_subtraction(&normal, &pixel->intersection, &pixel->sphere->xyz);
	norm_vector(&normal);
	vector_subtraction(&light_dir, &data->light->xyz,
		&pixel->intersection);
	norm_vector(&light_dir);

	light_intens = ang_bet_2_vec(&light_dir, &normal) 
		* data->light->ratio; // ratio_light??
	if (light_intens > 0)
		return (light_intens);
	return ( 0);
}

void pixel_computing_sphere(t_entire *data, t_pixel *pixel)
{

	int		light;
	float	light_ratio;

	ft_mlx_pixel_put_img(&data->simg, pixel->x, pixel->y, pixel->sphere->color_ambient);
	if (!data->light || check_for_shadow(data, pixel))
		return ;
	light_ratio = pixel_comp_sphere_refl_ratio(data, pixel);
	if (light_ratio <= 0)
		return ;
	light = color_diffusal(pixel->sphere->color_ambient, pixel->sphere->color,
		data->light->color, light_ratio);
	ft_mlx_pixel_put_img(&data->simg, pixel->x, pixel->y, light);

	return ;
}

static	t_crd	norm_cyl(t_pixel *pixel)
{
	t_crd	v;
	t_crd	res;

	if (pixel->cyl_type == PIPE)
	{
		scalar_multiplication(&v, &pixel->cyl->norm_vec,
			pixel->cyl_m);
		vector_subtraction(&res, &pixel->intersection, &pixel->cyl->xyz);
		vector_subtraction(&res, &res, &v);
	}
	else if (pixel->cyl_type == PLANE_BEGIN)
		res = pixel->cyl->plato_begin.norm_vec;
	else
		res = pixel->cyl->plato_end.norm_vec;
		
	norm_vector(&res);
	return (res);
}

static	float pixel_comp_cyl_refl_ratio(t_entire *data, t_pixel *pixel)
{
	t_crd	light_dir;
	t_crd	normal;
	float	light_intensity;

	normal = norm_cyl(pixel);
	vector_subtraction(&light_dir, &data->light->xyz,
		&pixel->intersection);
	norm_vector(&light_dir);
	light_intensity = ang_bet_2_vec(&light_dir, &normal)
		* data->light->ratio;
	if (light_intensity > 0)
		return (light_intensity);
	return (0);
}

void	pixel_computing_cyl(t_entire *data, t_pixel *pixel)
{
	int		light;
	float	light_ratio;

	ft_mlx_pixel_put_img(&data->simg, pixel->x, pixel->y,
		pixel->cyl->color_ambient);
	if (!data->light || check_for_shadow(data, pixel))
		return ;
	light_ratio = pixel_comp_cyl_refl_ratio(data, pixel);
	if (light_ratio <= 0)
		return ;
	light = color_diffusal(pixel->cyl->color_ambient, 
			pixel->cyl->color, data->light->color, 
			light_ratio);
	ft_mlx_pixel_put_img(&data->simg, pixel->x, pixel->y, light);
	return ;
}
