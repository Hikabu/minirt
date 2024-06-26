/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:12:48 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_entire	data;

	data.scene = parser(argc, argv);
	init_image(&data);
	new_image(&data.img);
	data.nearest_obj = NULL;
	data.nearest_type = NO_INTERSECT;
	data.prev_keyhook = 0;
	raytracer(&data);
	hook(&data);
	mlx_loop(data.mlx);
	minirt_close(&data);
	exit (0);
}

int	minirt_close(t_entire *data)
{
	free_scene(data->scene);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}
