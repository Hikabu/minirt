/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:34:51 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/04 20:19:46 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_scene_characteristics(t_scene *scene); 
void		print_coordinate(t_crd *coord, char *endchar);
void		print_color(int color);

void	print_spheres(t_sphere	*sp, char type)
{
	int	i;

	i = 0;
	while (sp)
	{
		if (type == 'a')
			printf("\e[0;33mSphere %d: \e[0m", i++);
		else
			printf("\e[0;33mSphere: \e[0m");
		printf("\t\e[0;34mPoint: \e[0m");
		print_coordinate(&sp->point, "\n");
		printf("        \t\e[0;34mDiameter: \e[0m%f\n",
			sp->diametr);
		print_color(sp->rgb[0]);
		print_color(sp->color_ambient);
		sp = sp->next;
		if (type != 'a')
			break ;
	}
}
void	print_color(int color)
{
	printf("        \t\e[0;34mColor, RGB:\t \e[0m%d, %d, %d\t[0x%x]\n",
		color >> 16 & 255, color >> 8 & 255, color & 255, color & 0xffffff);
}
void	print_coordinate(t_crd *coord, char *endchar)
{
	printf("(%f, %f, %f)", coord->x, coord->y, coord->z);
	if (endchar)
		printf("%s", endchar);
}

static void	print_scene_characteristics(t_scene *scene)
{
	printf("\e[0;32mCamera_point: \e[0m");
	print_coordinate(&scene->camera_point, "\n");
	printf("\e[0;32mCamera_angles: \e[0m%f\t%f\n", scene->camera_angeles[0],
		scene->camera_angeles[1]);
	printf("\e[0;32mCamera_orientation: \e[0m");
	print_coordinate(&scene->camera_orientation, "\n");
	printf("\e[0;32mCamera_fov: \e[0m%f\n", scene->camera_fov);
}

void	print_scene(t_scene	*scene)
{
	printf("\n\tOne pixel struct is %lu bits,\n\
	One data struct is %lu bits,\n\
	One scene struct is %lu bits,\n\
	One entire struct is %lu bits,\n\
	One sphere struct is %lu bits,\n\
	One plane struct is %lu bits,\n\
	One cylinder struct is %lu bits,\n\
	One light struct is %lu bits,\n",
		sizeof(t_pixel), sizeof(t_data), sizeof(t_scene), sizeof(t_entire),
		sizeof(t_sphere), sizeof(t_plane),
		sizeof(t_cyl), sizeof(t_light));
	print_scene_characteristics(scene);
	
	if (scene->ent && scene->ent->sphere)
		print_spheres(scene->ent->sphere, 'a');
	
}