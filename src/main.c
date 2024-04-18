/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/08 21:20:59 by vfedorov         ###   ########.fr       */
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



/////////////////////////////////////////////////////////

int	clos(t_pixel *scene)
{
	(void)scene;
	// exit_code(0, "finish\n", scene, NULL);
	exit(1);

	return (0);
}


int	camera_direction(int code, t_entire *all)
{
	int	k;

	k = 5;
	if (code == 65362 || code == 126)
		all->light->xyz.y = all->light->xyz.y + k;
	else if (code == 65364 || code == 125)
		all->light->xyz.y = all->light->xyz.y - k;
	else if (code == 65361 || code == 123)
		all->light->xyz.x = all->light->xyz.x + k;
	else if (code == 65363 || code == 124)
		all->light->xyz.x = all->light->xyz.x - k;
	else if (code == 65436)
		all->light->xyz.z = all->light->xyz.z + k;
	else if (code == 65438)
		all->light->xyz.z = all->light->xyz.z - k;
	ray_trace(all);
	return (0);
}

int	key_hook_man(int code, t_entire *all)
{
	int	k;

	k = 5;
	if (code == 65307 || code == 53)
		// exit_code(0, "finish_esc\n", NULL, NULL);
		error(1);
	else if (code == 119 || code == 13)
		all->camera->xyz.y = all->camera->xyz.y + k;
	else if (code == 115 || code == 1)
		all->camera->xyz.y = all->camera->xyz.y - k;
	else if (code == 97 || code == 0)
		all->camera->xyz.x = all->camera->xyz.x + k;
	else if (code == 100 || code == 2)
		all->camera->xyz.x = all->camera->xyz.x - k;
	else if (code == 113)
		all->camera->xyz.z = all->camera->xyz.z + k;
	else if (code == 101)
		all->camera->xyz.z = all->camera->xyz.z - k;
	camera_direction(code, all);
	return (0);
}

int key_hook(int keycode, void *param)
{
	printf("keycode: %d\n", keycode);
	(void)param;
	return (0);
}



/////////////////////////////////////////////////////////




int	main(int ac, char **av)
{
	t_entire	entire;
	
	if (ac != 2)
		error(2);
	if (open_and_parse_file(&entire, av[1]) == 0)
	{
		print_scene(&entire, entire.scene);
		init_image(&entire);


		mlx_key_hook(entire.window, key_hook_man, &entire);
		mlx_hook(entire.window, 17, 0, clos, &entire.pixel);
		ray_trace(&entire);
		mlx_loop(entire.mlx);
		// all_exiests(entire); 
	}
	// else 
	// 	perror("Not successful");
	(void)entire;
	(void)av;
	return (0);
}
