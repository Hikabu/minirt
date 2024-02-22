/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:53:56 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/21 22:07:33 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

void	ray_trace(t_data *data)
{
    int        mlx_x = 0;
    int        mlx_y = 0; // mlx_put_pixel
    float x_angle;
    float y_angle;
    int color;
    t_vector *ray;
    t_vplane *vplane;

    vplane = get_view_plane(scene->width, scene->height, scene->cams->fov);
    y_angle = (scene->hight / 2);
    while (y_angel >= (scene->hight / 2) * (-1))
    {
        
    }
    
}

// t_vplane    *get_view_plane(float width, float height, float fov)
// {
//     t_vplane *vplane;
//     float aspect_ratio;
    
//     vplane = malloc(sizeof(t_vplane));
//     if (!vplane)
//         return (NULL);
//     aspect_ratio = width / height;
//     vplane->width = 1;
//     vplane->height = vplane->width / aspect_ratio;
//     vplane->x_pixel = vplane->width / width;
//     vplane->y_pixel = vplane->height / height;
//     return (vplane);
// }