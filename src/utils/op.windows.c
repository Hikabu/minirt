/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:13:59 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/25 10:10:41 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_window(t_global *glob)
{
	glob->mlx = mlx_init();
	if(!glob->mlx)
		error(1);
	glob->mlx_window = mlx_new_window(glob->mlx, WIDTH, HEIGHT, "miniRT");
	if(!glob->mlx_window)
		error(1);
	
}