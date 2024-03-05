#include "minirt.h"

void	init_sp(t_sphere *list)
{
	list->id = 6;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->diametr = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	init_ent(t_entire *ent)
{
	t_scene *scene;

	scene = malloc(sizeof(t_scene));
	ent->scene = scene;
	initial_scene(ent->scene);
	ent->amlight = NULL;
	ent->scene->camera = NULL;
	ent->light = NULL;
	ent->plane = NULL;
	ent->cyl = NULL;
	ent->sphere = NULL;
}
