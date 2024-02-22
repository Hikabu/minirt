/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/22 21:40:15 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	all_exists(t_entire *ent)
{
	if (!ent->amlight || !ent->camera
		|| !ent->light || !ent->plane
		|| !ent->cyl || !ent->sphere)
		error_with_free(ent);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->simg.line_length + x * (data->simg.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, void *param)
{
	printf("keycode: %d\n", keycode);
	(void)param;
	return (0);
}

int	main(int ac, char **av)
{
	t_entire	entire;
	t_entire	*ent;
	void		*mlx;
	void		*win;
	int 		x = WIDTH;
	int 		y = HEIGHT;
	// t_data		data;
	t_data		img;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	while (x >= 0)
	{
		y = HEIGHT;
		while (y >= 0)
		{
			double result = pow(x - WIDTH/2, 2) + pow(y - HEIGHT/2, 2);
			if (result <= pow(100, 2))
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y--;
		}
		x--;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	// init_image(&data);
	// color_back(&data.simg.img);
	mlx_loop(mlx);
	init_ent(&entire);
	ent = &entire;
	if (ac != 2)
		error(2);
	readmap(av[1], &ent);
	all_exists(ent);
	// print_entire(&ent);
	// system("leaks miniRT");
	(void)win;
	return (0);
}

