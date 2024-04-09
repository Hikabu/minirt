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
	if (open_and_parse_file(&entire, av[1]) == 0)
	{
		print_scene(&entire, entire.scene);
		init_image(&entire);
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
