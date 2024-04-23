/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_readsphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:04 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 12:17:12 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*parser_addsphere(t_parser *p)
{
	t_sphere	*sphere;

	if (!p->scene->obj->spheres)
	{
		p->scene->obj->spheres = (t_sphere *) malloc (sizeof(t_sphere));
		if (!(p->scene->obj->spheres))
			parser_error (12, p);
		p->scene->obj->spheres->next = 0;
		return (p->scene->obj->spheres);
	}
	sphere = p->scene->obj->spheres;
	while (sphere && sphere->next)
		sphere = sphere->next;
	sphere->next = (t_sphere *) malloc (sizeof(t_sphere));
	if (!(sphere->next))
		parser_error (12, p);
	sphere->next->next = 0;
	return (sphere->next);
}

void	parser_readsphere(t_parser *p)
{
	t_sphere	*sphere;

	sphere = parser_addsphere(p);
	(p->i) += 2;
	parser_error_space(p);
	sphere->point = parser_readcoord(p);
	parser_error_space(p);
	sphere->diameter = parser_readfloat(p);
	parser_error_space(p);
	if (!ft_isdigit(p->str[p->i]))
		parser_error(1, p);
	sphere->color = parser_readcolor(p);
	parser_skipspaces(p->str, &(p->i));
	if (p->str[p->i])
		parser_error(1, p);
}
