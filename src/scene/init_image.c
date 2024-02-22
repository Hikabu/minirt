/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/22 21:00:42 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	color_back(void	*img)
// {
// 	int	x;
// 	int	y;

// 	if (!img)
// 		error(1);
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 			my_mlx_pixel_put(img, x, y++, BACKGROUND);
// 		x++;
// 	}
// }

// void	init_image(t_data *data)
// {
// 	data->mlx = mlx_init();
// 	if (!data->mlx)
// 		error(1);
// 	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "minirt");
// 	data->simg.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	if (!data->window)
// 		error(1);
// 	mlx_put_image_to_window(data->mlx, data->window, data->simg.img, 0, 0);
// 	 mlx_loop(data->mlx);
// 	data->simg.addr = mlx_get_data_addr(data->simg.img,
// 			&(data->simg.bits_per_pixel), &(data->simg.line_length), &(data->simg.endian));
// 	if (!data->simg.addr)
// 		error(1);
// }