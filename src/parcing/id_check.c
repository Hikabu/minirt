#include "minirt.h"

void	id_check3(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "sp"))
	{
		if ((*ent)->sphere)
		{
			tmp = (*ent)->sphere;
			ft_lstadd_back_sphere(&((*ent)->sphere), to_struct_sp(str));
		}
		(*ent)->sphere = to_struct_sp(str);
		if (tmp)
			(*ent)->sphere = tmp;
	}
	else if (!ft_strncmp(str[0], "#", 1))
		return ;
	else
		error_with_free(*ent);
	printf("%d\n", (*ent)->camera->fov);
}

void	id_check2(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "cy"))
	{
		if ((*ent)->cyl)
		{
			tmp = (*ent)->cyl;
			ft_lstadd_back_cyl(&((*ent)->cyl), to_struct_cy(str));
		}
		(*ent)->cyl = to_struct_cy(str);
		if (tmp)
			(*ent)->cyl = tmp;
	}
	else
		id_check3(str, ent);
}

void	id_check1(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "L"))
	{
		if ((*ent)->light)
			error_with_free(*ent);
		(*ent)->light = to_struct_l(str);
	}
	else if (!ft_strcmp(str[0], "pl"))
	{
		if ((*ent)->plane)
		{
			tmp = (*ent)->plane;
			ft_lstadd_back_plane(&((*ent)->plane), to_struct_pl(str));
		}
		(*ent)->plane = to_struct_pl(str);
		if (tmp)
			(*ent)->plane = tmp;
	}
	else
		id_check2(str, ent);
}

void	id_check(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "A"))
	{
		if ((*ent)->amlight)
			error_with_free(*ent);
		(*ent)->amlight = to_struct_a(str);
	}
	else if (!ft_strcmp(str[0], "C"))
	{
		if ((*ent)->camera)
			error_with_free(*ent);
		(*ent)->camera = to_struct_c(str);
	}
	else
		id_check1(str, ent);
}
