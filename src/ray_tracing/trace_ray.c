/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:53:56 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/26 15:28:09 by vfedorov         ###   ########.fr       */
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
/*
rt - behavior simulation of light rays for realistik image. 
To do this, we need to know which direction to send the rays 
from the camera. This is FOV angles. we calculate horizontal and vertical
angeles (width and hight but in degrees)


*/
void	get_fov_angles(t_entire *ent, t_scene *scene)
{
	printf("camera in function and fov is  %zu\n", ent->camera->fov);
	// float vertical_angle = tan(camera_fov_rad / 2);  // calculate distance from the camera to the plane that intersects
	// float aspect_ratio = (float)HEIGHT / (float)WIDTH;
	ent->scene->camera_angeles[0] = tan(ent->camera->fov * M_PI / 360); // vertical angle in radians
	ent->scene->camera_angeles[1] = (scene->camera_angeles[0]
			* (((float)HEIGHT) / ((float)WIDTH))); 
	printf("camera in function and cqmera_point is %f\n", scene->camera_angeles[0]);
	printf("camera in function and cqmera_point for 1 is %f\n", scene->camera_angeles[1]);
}

void	ray_trace(t_entire *data)
{
	float lambda; //angular change per pixel horizontally
	t_pixel pixel;
/* what we need is iterate over each pixel in figure
For each pixel - cast a ray into the scene in the direction specified by vector
Calculate the color of the pixel based on the materials, lighting, and other factors at the point of intersection
Write the color to the pixel in image */ 
	fill_new_vector(&pixel.ray.point[0], 0, 0, -1); //z for away from the viewer and direction of a ray (pixel)
	lambda = 2 * data->scene->camera_angeles[0] / WIDTH;
	// printf("angel is %f\n", data->scene->camera_angeles[0]);
	dprintf(1, "lambda is %f\n", lambda);
	pixel.y = 0;
	while  (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			pixel_init(&pixel);
			// printf("pixel.ray = %f\n", pixel.ray.point[0].x);
			fill_new_vector(&(pixel.ray.point[1]), 
				-data->scene->camera_angeles[0] + lambda * pixel.x,
				+data->scene->camera_angeles[1] + lambda * pixel.y, 1); //shoot rays from the camera towards the scene for color calculation.
			printf("ray point[1] is %f %f %f\n", pixel.ray.point[1].x, pixel.ray.point[1].y, pixel.ray.point[1].z);
			check_intersection(data, &pixel);
			pixel_computing(data, &pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->simg.img, 0, 0);
	// color_back(&(data->img)); // if we will increase image for black fone
}
