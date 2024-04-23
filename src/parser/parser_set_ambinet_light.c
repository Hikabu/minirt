/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_ambinet_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:09 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:21:19 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parcing.h"

static int	parser_return_coam(int color1, int color2, float intensity)
{
	int	res;

	res = ((int)(intensity
				* (((color1 >> 16 & 255) * (color2 >> 16 & 255)) / 255))) << 16;
	res |= (int)(intensity
			* (((color1 >> 8 & 255) * (color2 >> 8 & 255) / 255))) << 8;
	res |= (int)(intensity
			* (((color1 & 255) * (color2 & 255) / 255)));
	return (res);
}

static void	parser_fill_coam_sp_pl(t_parser *parser)
{
	t_sphere	*sphere;
	t_plane		*planes;

	sphere = parser->scene->obj->spheres;
	while (sphere)
	{
		sphere->color_ambient = parser_return_coam(sphere->color,
				parser->scene->ambient_light_rgb,
				parser->scene->ambient_light_intensity);
		sphere = sphere->next;
	}
	planes = parser->scene->obj->planes;
	while (planes)
	{
		planes->color_ambient = parser_return_coam(planes->color,
				parser->scene->ambient_light_rgb,
				parser->scene->ambient_light_intensity);
		planes = planes->next;
	}
}

void	parser_fill_coam(t_parser *parser)
{
	t_cylinder	*cylinder;

	parser_fill_coam_sp_pl(parser);
	cylinder = parser->scene->obj->cylinders;
	while (cylinder)
	{
		cylinder->color_ambient = parser_return_coam(cylinder->color,
				parser->scene->ambient_light_rgb,
				parser->scene->ambient_light_intensity);
		cylinder = cylinder->next;
	}
}
