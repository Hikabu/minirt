/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/19 17:49:14 by valeriafedo      ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_entire	entire;
	t_entire	*ent;

	init_ent(&entire);
	ent = &entire;
	if (ac != 2)
		error("two arguments required: exec and scene\n");
	readmap(av[1], &ent);
	// printf("---------\namlight\nid = %d\nratio = %f\nRGB = %d,%d,%d\n----------\n", 
		//ent->amlight->id, ent->amlight->ratio, ent->amlight->rgb[0], ent->amlight->rgb[1], ent->amlight->rgb[2]);
	all_exists(ent);
	mlx_tracing(ent);
	system("leaks miniRT");
	return (0);
}
