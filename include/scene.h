/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:05:37 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/21 18:34:48 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parcing.h"

typedef struct s_sphere t_sphere;
typedef struct s_data	t_data;
typedef struct s_img	t_img;
typedef struct s_entire	t_entire;

typedef struct s_vector
{
    float x;
    float y;
    float z;
}   t_vector;

// typedef struct s_sphere
// {
// 	int				id;
// 	float			xyz[3];
// 	float			radius;
// 	int				rgb[3];
// 	t_vector		*center;
// 	struct s_sphere	*next;
// }	t_sphere;

float vec_product(t_vector *vec1, t_vector *vec2);
void vec_normalize(t_vector *vec);
float vec_length(t_vector *vec);
t_vector	*vecsubtraction(t_vector *vec1, t_vector *vec2);
t_vector	*vector_init(float x, float y, float z);
void	init_image(t_data *data);
void	all_exists(t_entire *ent);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	key_hook(int keycode, void *param);

void	color_back(void	*img);
// camera
typedef struct s_camera
{
	int			id;
	float		xyz[3];
	float		norm_vec[3];
	int			fov;
	t_vector	*origin;
	t_vector	*direction;
}	t_camera;

t_camera	*init_camera(t_vector *origin, t_vector *direction, float fov);

typedef struct s_scene
{
	t_camera	*cameras;
	t_sphere	*sphere;
	float		width;
	float		height;
}   t_scene;

// scene 
t_scene	*init_scene(t_camera *camera, t_sphere *sphere);

typedef struct s_vplane
{
	float width;
	float height;
	float x_pixel;
	float y_pixel;
	
} t_vplane;
t_vplane    *get_view_plane(float width, float height, float fov);


#endif