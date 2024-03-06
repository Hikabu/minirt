/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:33 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/29 16:34:41 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	calculating_sphere(t_data *data)
// {
// 	int		light;
// 	float	lightning_ratio;

// 	my_mlx_pixel_put(&data->img, WIDTH, HEIGHT, 0x00FF0000);
// 	// if (!data->scene->obj->lights || check_for_shadow(data, pixel))
// 	// 	return ;
// 	// lightning_ratio = pixel_computing_sphere_diffusal_recflect_ratio
// 	// 	(data, pixel);
// 	if (lightning_ratio <= 0)
// 		return ;
// 	// light = color_diffusal(pixel->sphere->color_ambient, pixel->sphere->color,
// 	// 		data->scene->obj->lights->color, lightning_ratio);
// 	my_mlx_pixel_put(&data->img, WIDTH, HEIGHT, light);
// 	return ;
// }