/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/27 21:37:32 by vfedorov         ###   ########.fr       */
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


int key_hook(int keycode, void *param)
{
	printf("keycode: %d\n", keycode);
	(void)param;
	return (0);
}

int	main(int ac, char **av)
{
	t_entire	entire;
	
	if (ac != 2)
		error(2);
	// init_all(&entire);
	if (open_and_parse_file(&entire, av[1]) == 0)
	{
		// printf("ibfuckinghere\n");
		// readmap(av[1], &entire, &entire);
		// print_entire(&entire);
		// entire.scene->camera_point = entire->scene->camera_point;
		// entire->scene = NULL;
		// entire.scene = entire.scene;
		// entire.scene->obj->sphere = entire.scene->obj->sphere;
		print_scene(&entire, entire.scene);
		// init_image(&entire);
		// color_back(entire.img);
	// 	entire.scene = entire.scene;
		ray_trace(&entire);
	// // printf("entire->mlx2 = %p\n", entire.mlx);
		// mlx_loop(entire.mlx);
		// all_exiests(entire);
		// printf("camera after function %f\n", entire->scene->camera_point.z);
		// system("leaks miniRT");
		// (void)win;
		// (void)av;
	}
	// else 
	// 	perror("Not successful");
	(void)entire;
	(void)av;
	return (0);
}
