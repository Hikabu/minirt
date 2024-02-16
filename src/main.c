/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/13 15:49:35 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	all_exists(t_entire *ent)
{
	if (!ent->amlight || !ent->camera
		|| !ent->light)
		error_with_free(ent, 1);
}

int	main(int ac, char **av)
{
	t_entire	entire;
	t_entire	*ent;

	init_ent(&entire);
	ent = &entire;
	if (ac != 2)
		error(2);
		// (void)av;
	readmap(av[1], &ent);
	all_exists(ent);
	print_entire(&ent);
	error_with_free(ent, 0);
	system("leaks miniRT");
	return (0);
}
