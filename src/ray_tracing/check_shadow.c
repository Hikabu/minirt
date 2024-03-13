/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:53:19 by vfedorov          #+#    #+#             */
/*   Updated: 2024/03/13 16:12:17 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int    check_for_shadow_sphere(t_data *data, t_ray *ray, t_crd *crd)
{
    t_sphere    *sphere;
    float       lenght;

    sphere = data->scene->obj->sphere;
    lenght = -1;
    while (sphere)
    {
        lenght = check_intersection_sphere(sphere, ray, crd);
        if (lenght > MIN_TRASHOLD && lenght < MAX_TRASHOLD)
            return (1);
        sphere = sphere->next;
    }
    return (0);
}
