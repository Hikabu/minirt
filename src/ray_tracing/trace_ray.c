/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:53:56 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/05 00:41:56 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pixel_init(t_pixel *pixel)
{
	pixel->ray.point[1].x = 0;
	pixel->ray.point[1].y = 0;
	pixel->ray.point[1].z = 0;
	pixel->plane = 0;
	pixel->sphere = 0;
	pixel->cyl = 0;
	pixel->lenght = 0;
	pixel->coor.x = 0;
	pixel->coor.y = 0;
	pixel->coor.z = 0;
}

void	get_fov_angles(t_scene *scene)
{
	scene->camera_angeles[0] = tan(scene->camera_fov * M_PI / 360);
	scene->camera_angeles[1] = (scene->camera_angeles[0]
			* (((float)HEIGHT) / ((float)WIDTH))); 
}
void	fill_coordinates_for_camera(t_camera *camera, t_crd *camera_point)
{
	camera_point->x = camera->xyz[0];
	camera_point->y = camera->xyz[1];
	camera_point->z = camera->xyz[2];
	// return(&scene->camera_point);
}
void	ray_trace(t_data *data)
{
	float lambda; //angular change per pixel horizontally
	t_pixel pixel;
// what we need is iterate over each pixel in figure
//For each pixel - cast a ray into the scene in the direction specified by vector
// Calculate the color of the pixel based on the materials, lighting, and other factors at the point of intersection
// Write the color to the pixel in image

	fill_new_vector(&pixel.ray.point[0], 0, 0, -1); //z for away from the viewer and direction of a ray (pixel)
	lambda = 2 * data->scene->camera_angeles[0] / WIDTH;
	pixel.y = 0;
	while  (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.y < WIDTH)
		{
			pixel_init(&pixel);
			fill_new_vector(&(pixel.ray.point[1]), 
				-data->scene->camera_angeles[0] + lambda * pixel.x,
				+data->scene->camera_angeles[1] + lambda * pixel.y, 1);
			check_intersection(data, &pixel);
			pixel_computing(data, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
}
