/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:06:26 by timelkon          #+#    #+#             */
/*   Updated: 2024/02/26 18:06:30 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_free_exit(1);
	aspect_ratio = width / height;
	vplane->width = 1;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int	mlx_x;
	int	mlx_y;
	float	x_angle;
	float	y_angle;
	int		color;
	float	x_ray;
	float	y_ray;
	t_vector	*ray;
	t_vplane	*vplane;

	vplane = get_view_plane(scene->width, scene->height, scene->cameras->fov);
	y_angle = (scene->height / 2);
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vector_init(x_ray, y_ray, -1);
			vec_normalize(ray);
			//////////////////////
		}
	}
}

void	mlx_tracing(t_entire *ent)
{
	void	*mlx;
	void	*window;
	t_scene	*scene;

	scene = init_scene(ent->camera, ent->sphere, 800, 600);
	mlx = mlx_init();
	mlx = mlx_new_window(mlx, scene->width, scene->height, "U-LA-LA");
	ray_tracing(mlx, window, scene);
	mlx_loop(mlx);
}