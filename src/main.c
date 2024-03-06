/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/04 21:05:35 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	all_exiests(t_entire *ent)
{
	if (!ent->amlight || !ent->scene->camera
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
	t_data		data;
	
	if (ac != 2)
		error(2);
	init_ent(&entire);
	ent = &entire;
	readmap(av[1], &ent, &data);
	print_entire(&ent);
	data.scene->camera_point = ent->scene->camera_point;
	// ent->scene = NULL;
	print_scene(data.scene);
	init_image(&data);
	color_back(&data.simg.img);
	ray_trace(&data);
	// mlx_loop(data.mlx);
	all_exiests(ent);
	// printf("camera after function %f\n", ent->scene->camera_point.z);
	// system("leaks miniRT");
	// (void)win;
	// (void)av;
	return (0);
}
