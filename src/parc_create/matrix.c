/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:35:59 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/13 21:42:44 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    translate_obj(t_scene *scene, t_crd *crd)
{
    t_obj   obj;

    obj = *scene->obj;
    while (obj.sphere)
    {
        vector_subtraction(&obj.sphere->xyz, &obj.sphere->xyz, crd);
        obj.sphere = obj.sphere->next;
    }
    while (obj.plane)
    {
        vector_subtraction(&obj.plane->xyz, &obj.plane->xyz, crd);
        obj.plane = obj.plane->next;
    }
    while (obj.cyl)
    {
        vector_subtraction(&obj.cyl->xyz, &obj.cyl->xyz, crd);
        obj.cyl = obj.cyl->next;
    }
    while (obj.light)
    {
        vector_subtraction(&obj.light->xyz, &obj.light->xyz, crd);
        obj.light = obj.light->next;
    }
}

