/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:05:37 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/01 15:58:18 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_vector
{
    float x;
    float y;
    float z;
}   t_vector;

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
}			t_sphere;
float vec_product(t_vector *vec1, t_vector *vec2);
void vec_normalize(t_vector *vec);
float vec_length(t_vector *vec);
t_vector	*vecsubtraction(t_vector *vec1, t_vector *vec2);
t_vector	*vector_init(float x, float y, float z);

//figures
t_sphere    *init_sphere(t_vector *center, float radius);


//camera
typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		fov;	// ygol obzora
}   t_camera;

t_camera	*init_camera(t_vector *origin, t_vector *direction, float fov);

typedef struct s_scene
{
	t_camera	*cameras;
	t_sphere	*sphere;
	float		width;
	float		height;
}   t_scene;

t_scene	*init_scene(t_camera *camera, t_sphere *sphere);
#endif