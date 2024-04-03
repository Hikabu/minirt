/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/03 18:48:54 by vfedorov         ###   ########.fr       */
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
			ft_mlx_pixel_put_img(img, x, y++, BACKGROUND);
		x++;
	}
}
//lets do our color struct int


t_color	*int_to_rgb(const int r, const int g, const int b)
{
	t_color	*rgb;

	if(!(rgb = malloc(sizeof(*rgb))))
		error(1);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}
// // ft_put_pixel(img->data, pixel, rgb_to_int(*color), scene->resolution);
// void	ft_mlx_pixel_put_img(unsigned char *data, int x, int y,  const int color)
// {
// 	int	(*tab)[x][1]; // prepare the cast

// 	tab = (void *)data; // cast for change 1 dimension array to 2 dimensions
// 	*tab[y][x] = color; // set the pixel at the coord x,y with the color value
// }
void	ft_mlx_pixel_put_img(t_img *img, int x, int y, const int color) //set that color in the image
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void	init_image(t_entire *data)
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
	if (!data->simg.addr)
		error(1);
}
