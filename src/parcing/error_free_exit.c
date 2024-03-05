#include "minirt.h"

void	error_with_free2(t_entire *ent, void *tmp)
{
    while (ent->sphere)
	{
		if (ent->sphere->next)
		{
			tmp = ent->sphere;
			ent->sphere = ent->sphere->next;
			free(tmp);
		}
		else
			free(ent->sphere);
	}
	error(1);
}

void	error_with_free1(t_entire *ent, void *tmp)
{
	while (ent->cyl)
	{
		if (ent->cyl->next)
		{
			tmp = ent->cyl;
			ent->cyl = ent->cyl->next;
			free(tmp);
		}
		else
			free(ent->plane);
	}
	error_with_free2(ent, NULL);
}

void	error_with_free(t_entire *ent)
{
	void	*tmp;

	tmp = NULL;
	if (ent->amlight)
		free(ent->amlight);
	if (ent->scene->camera)
		free(ent->scene->camera);
	if (ent->light)
		free(ent->light);
	while (ent->plane)
	{
		if (ent->plane->next)
		{
			tmp = ent->plane;
			ent->plane = ent->plane->next;
			free(tmp);
		}
		else
			free(ent->plane);
	}
	error_with_free1(ent, NULL);
}

void	error(int er)
{
	if (er == 1)
	{
		printf("Error\n");}
	else if (er == 2)
		printf ("u need two arguments: exec and map\n");
	exit(1);
}
