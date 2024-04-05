/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/05 17:52:53 by vfedorov         ###   ########.fr       */
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
