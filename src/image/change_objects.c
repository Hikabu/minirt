/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:12 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:08:40 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rotate_cylinder(int keycode, t_entire *global);
static void	rotate_plane(int keycode, t_entire *global);

void	change_sphere(int keycode, t_entire *global)
{
	if (global->prev_keyhook == X_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_sphere *)(global->nearest_obj))->point.x += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_sphere *)(global->nearest_obj))->point.x -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Y_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_sphere *)(global->nearest_obj))->point.y += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_sphere *)(global->nearest_obj))->point.y -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Z_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_sphere *)(global->nearest_obj))->point.z += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_sphere *)(global->nearest_obj))->point.z -= STEP_TRANSLATE;
	}
}

void	change_cylinder(int keycode, t_entire *global)
{
	if (keycode == UP || keycode == DOWN)
		rotate_cylinder(keycode, global);
	else if (global->prev_keyhook == X_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_cylinder *)(global->nearest_obj))->point.x += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_cylinder *)(global->nearest_obj))->point.x -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Y_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_cylinder *)(global->nearest_obj))->point.y += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_cylinder *)(global->nearest_obj))->point.y -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Z_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_cylinder *)(global->nearest_obj))->point.z += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_cylinder *)(global->nearest_obj))->point.z -= STEP_TRANSLATE;
	}
}

static void	rotate_cylinder(int keycode, t_entire *global)
{
	if (global->prev_keyhook == X_KEYHOOK)
	{
		if (keycode == UP)
			((t_cylinder *)(global->nearest_obj))->orientation.x += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_cylinder *)(global->nearest_obj))->orientation.x -= STEP_ROTATE;
	}
	else if (global->prev_keyhook == Y_KEYHOOK)
	{
		if (keycode == UP)
			((t_cylinder *)(global->nearest_obj))->orientation.y += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_cylinder *)(global->nearest_obj))->orientation.y -= STEP_ROTATE;
	}
	else if (global->prev_keyhook == Z_KEYHOOK)
	{
		if (keycode == UP)
			((t_cylinder *)(global->nearest_obj))->orientation.z += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_cylinder *)(global->nearest_obj))->orientation.z -= STEP_ROTATE;
	}	
	normalizing_vector(&((t_cylinder *)(global->nearest_obj))->orientation,
		&((t_cylinder *)(global->nearest_obj))->orientation);
}

void	change_plane(int keycode, t_entire *global)
{
	if (keycode == UP || keycode == DOWN)
		rotate_plane(keycode, global);
	if (global->prev_keyhook == X_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_plane *)(global->nearest_obj))->point.x += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_plane *)(global->nearest_obj))->point.x -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Y_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_plane *)(global->nearest_obj))->point.y += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_plane *)(global->nearest_obj))->point.y -= STEP_TRANSLATE;
	}
	else if (global->prev_keyhook == Z_KEYHOOK)
	{
		if (keycode == GREATER)
			((t_plane *)(global->nearest_obj))->point.z += STEP_TRANSLATE;
		else if (keycode == LESS)
			((t_plane *)(global->nearest_obj))->point.z -= STEP_TRANSLATE;
	}	
}

static void	rotate_plane(int keycode, t_entire *global)
{
	if (global->prev_keyhook == X_KEYHOOK)
	{
		if (keycode == UP)
			((t_plane *)(global->nearest_obj))->orientation.x += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_plane *)(global->nearest_obj))->orientation.x -= STEP_ROTATE;
	}
	else if (global->prev_keyhook == Y_KEYHOOK)
	{
		if (keycode == UP)
			((t_plane *)(global->nearest_obj))->orientation.y += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_plane *)(global->nearest_obj))->orientation.y -= STEP_ROTATE;
	}
	else if (global->prev_keyhook == Z_KEYHOOK)
	{
		if (keycode == UP)
			((t_plane *)(global->nearest_obj))->orientation.z += STEP_ROTATE;
		else if (keycode == DOWN)
			((t_plane *)(global->nearest_obj))->orientation.z -= STEP_ROTATE;
	}	
	normalizing_vector(&((t_plane *)(global->nearest_obj))->orientation,
		&((t_plane *)(global->nearest_obj))->orientation);
}
