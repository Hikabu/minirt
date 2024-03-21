/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/21 17:27:53 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_back(void	*img)
{
	int	x;
	int	y;

	if (!img)
		error(1);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			my_mlx_pixel_put(img, x, y++, BACKGROUND);
		x++;
	}
}
void	ft_mlx_pixel_put_img(t_img *img, int x, int y, int color) //take address from memory
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	init_image(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error(1);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "minirt");
	data->simg.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->window || !data->simg.img)
		error(1);
	mlx_put_image_to_window(data->mlx, data->window, data->simg.img, 0, 0);
	data->simg.addr = mlx_get_data_addr(data->simg.img,
			&(data->simg.bits_per_pixel), &(data->simg.line_length), &(data->simg.endian));
		// mlx_loop(data->mlx);
	printf("data->mlx = %p\n", data->mlx);
	if (!data->simg.addr)
		error(1);
}

// void	init_image(t_global *data)
// {
// 	data->mlx = mlx_init();
// 	if (!data->mlx)
// 		error_mlx(data);
// 	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "minirt");
// 	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	if (!data->window || !data->img.img)
// 		error_mlx(data);
// 	data->img.addr = mlx_get_data_addr(data->img.img,
// 			&(data->img.bpp), &(data->img.line_length), &(data->img.endian));
// 	if (!data->img.addr)
// 		error_mlx(data);
// }