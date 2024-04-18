/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:34:51 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/02 17:13:39 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_scene_characteristics(t_entire *ent, t_scene *scene);
void		print_color(int color);
void	print_coordinate(void *coord, char *endchar);

void	print_spheres(t_sphere *sp, char type)
{
	int	i;
	t_sphere *tmp = sp;
	
	i = 0;
	while (tmp)
	{
		if (type == 'a')
			printf("\e[0;33mSphere %d: \e[0m", i++);
		else
			printf("\e[0;33mSphere: \e[0m");
		printf("\t\e[0;34mPoint: \e[0m");
		print_coordinate(&sp->xyz, "\n"); 
		printf("        \t\e[0;34mDiameter: \e[0m%f\n",
			sp->diametr);
		print_color(sp->color);
		print_color(sp->color_ambient);
		tmp = tmp->next;
		if (type != 'a')
			break ;
	}
}

void	print_lights(t_light *l)
{
	int	i;

	i = 0;

	printf("\e[0;33mLight %d: \e[0m", i++);
	printf("\t\e[0;34mPoint: \e[0m");
	print_coordinate(&l->xyz, "\n");
	printf("        \t\e[0;34mLighting ratio: \e[0m%f\n",
		l->ratio);
	print_coordinate(&l->rgb, "\n");
}

void	print_cylinders(t_cyl *cy, char type)
{
	int	i;

	i = 0;
	while (cy)
	{
		if (type == 'a')
			printf("\e[0;33mCylinder %d: \e[0m", i++);
		else
			printf("\e[0;33mCylinder: \e[0m");
		printf("\t\e[0;34mPoint: \e[0m");
		print_coordinate(&cy->xyz, "\n");
		printf("        \t\e[0;34mOrientation: \e[0m");
		print_coordinate(&cy->norm_vec, "\n");
		print_color(cy->color);
		// print_coordinate(cy->color_ambient,  "\n");
		printf("        \t\e[0;34mDiameter: \e[0m%f\n",
			cy->diam);
		printf("        \t\e[0;34mHeight: \e[0m%f\n",
			cy->heig);
		cy = cy->next;
		if (type != 'a')
			break ;
	}
}

void	print_planes(t_plane *pl, char type)
{
	int	i;

	i = 0;
	while (pl)
	{
		if (type == 'a')
			printf("\e[0;33mPlane %d: \e[0m", i++);
		else
			printf("\e[0;33mPlane: \e[0m");
		printf("\t\e[0;34mPoint: \e[0m");
		print_coordinate(&pl->xyz, "\n");
		printf("        \t\e[0;34mOrientation: \e[0m");
		print_coordinate(&pl->norm_vec, "\n");
		print_color(pl->color);
		print_color(pl->color_ambient);
		pl = pl->next;
		if (type != 'a')
			break ;
	}
}


void print_all_objj(t_entire *entire)
{
    if (entire == NULL || entire->objj == NULL) {
        printf("No objj objects to print.\n");
        return;
    }
    printf("Printing all objj objects:\n");
    const t_objj *current = entire->objj;
    while (current != NULL) {
        // Print details of current objj object
        printf("ID: %d\n", current->id);

		t_plane *pl;
		t_sphere *sp;
		t_cyl *cy;

        switch (current->id) 
		{
            case id_plane:
                // printf("Type: Plane\n");
				pl = (t_plane *)&(current->object.plane);
				print_planes(pl, 'a');
                break;

            case id_sphere:
                // printf("Type: Sphere\n");
				sp = (t_sphere *)&(current->object.sphere);
				print_spheres(sp, 'a');
                break;
            case id_cyl:
                // printf("Type: Cylinder\n");
				cy = (t_cyl *)&(current->object.cylinder);
				print_cylinders(cy, 'a');
                break;
            // Add more cases if needed for other object types

            default:
                printf("Unknown object type\n");
                break;
        }

        // Print other details of objj if needed
        current = current->next; // Move to next objj object
    }
}


void	print_scene(t_entire *ent, t_scene	*scene)
{
	// printf("im here\n");
	// printf("\n\tOne pixel struct is %lu bits,\n\
	// One global struct is %lu bits,\n\
	// One scene struct is %lu bits,\n\
	// One obj struct is %lu bits,\n\
	// One sphere struct is %lu bits,\n\
	// One plane struct is %lu bits,\n\
	// One cylinder struct is %lu bits,\n\
	// One light struct is %lu bits,\n",
	// 	sizeof(t_pixel), sizeof(t_entire), sizeof(t_scene),
	// 	sizeof(t_obj), sizeof(t_sphere), sizeof(t_plane),
	// 	sizeof(t_cyl), sizeof(t_light));
	print_scene_characteristics(ent, scene);

    print_all_objj(ent);

	// if (ent->sphere)
	// 	print_spheres(ent->sphere, 'a');
	// if (ent->light)
	// 	print_lights(ent->light);
	// if (ent->plane)
	// 	print_planes(ent->plane, 'a');
	// if (ent->cyl)
	// 	print_cylinders(ent->cyl, 'a');
}

static void	print_scene_characteristics(t_entire *ent, t_scene *scene)
{
	printf("\e[0;32mCamera_point: \e[0m");
	print_coordinate(&ent->camera->xyz, "\n");
	printf("\e[0;32mCamera_angles: \e[0m%f\t%f\n", ent->scene->camera_angeles[0],
		ent->scene->camera_angeles[1]);
	printf("\e[0;32mCamera_orientation: \e[0m");
	print_coordinate(&ent->camera->norm_vec, "\n");
	printf("\e[0;32mCamera_fov: \e[0m%zu\n", ent->camera->fov);
	printf("\e[0;32mAmbient_light_intensity: \e[0m%f\n",
		ent->amlight->ratio);
	printf("\e[0;32mAmbient_light_rgb:\e[0m\t%d, %d, %d\n",
		scene->ambient_light_rgb >> 16 & 255,
		scene->ambient_light_rgb >> 8 & 255,
		scene->ambient_light_rgb & 255);
	printf("\e[0;32mObjects:\e[0m\n");
}

void	print_coordinate(void *crd, char *endchar)
{
	t_crd *coord = (t_crd *)crd;
	printf("(%f, %f, %f)", coord->x, coord->y, coord->z);
	if (endchar)
		printf("%s", endchar);
}


void	print_color(int color)
{
	printf("        \t\e[0;34mColor, RGB:\t \e[0m%d, %d, %d\t[0x%x]\n",
		color >> 16 & 255, color >> 8 & 255, color & 255, color & 0xffffff);
}