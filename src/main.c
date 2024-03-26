/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/26 15:09:26 by valeriafedo      ###   ########.fr       */
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

void	my_mlx_pixel_put(t_entire *data, int x, int y, int color)
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
	t_data		data;
	
	if (ac != 2)
		error(2);
	// init_all(&entire);
	if (open_and_parse_file(&entire, av[1]) == 0)
	{
		// printf("ibfuckinghere\n");
		// readmap(av[1], &ent, &data);
		// print_entire(&ent);
		// data.scene->camera_point = ent->scene->camera_point;
		// ent->scene = NULL;
		// data.scene = entire.scene;
		// data.scene->obj->sphere = entire.scene->obj->sphere;
		print_scene(&entire, entire.scene);
		// init_image(&entire);
		// color_back(entire.img);
	// 	data.scene = entire.scene;
		ray_trace(&entire);
	// // printf("data->mlx2 = %p\n", data.mlx);
		// mlx_loop(entire.mlx);
		// all_exiests(ent);
		// printf("camera after function %f\n", ent->scene->camera_point.z);
		// system("leaks miniRT");
		// (void)win;
		// (void)av;
	}
	// else 
	// 	perror("Not successful");
	(void)data;
	(void)entire;
	(void)av;
	return (0);
}
