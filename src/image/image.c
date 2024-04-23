/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:23 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:12:39 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	error_mlx(t_entire *data);

void	new_image(void *img)
{
	int	i;
	int	j;

	if (!img)
		return ;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			ft_mlx_pixel_put_img(img, i, j++, BACKGROUND_COLOR);
		i++;
	}	
}

void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color)
{
	char			*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_image(t_entire *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_mlx(data);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "minirt");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->window || !data->img.img)
		error_mlx(data);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bpp), &(data->img.line_length), &(data->img.endian));
	if (!data->img.addr)
		error_mlx(data);
}

static void	error_mlx(t_entire *data)
{
	free_scene(data->scene);
	perror(NULL);
	exit (12);
}
