/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:57:40 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/01 15:34:42 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*vector_init(float x, float y, float z)  // take pointer to vector and init it
{
    t_vector *vec;

    vec = malloc(sizeof(t_vector));
    if (!vec)
        error(1);
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return (vec);
}

t_vector	*vecsubtraction(t_vector *vec1, t_vector *vec2) // vec1 - vec2 
{
    t_vector *result;

	result = vector_init(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (result);
}

float vec_length(t_vector *vec) //find length of vector
{
	float result;
	
	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (result);
}

void vec_normalize(t_vector *vec) //normalize vector
{
	float length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

float	vec_product(t_vector *vec1, t_vector *vec2)
{
	float result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (result);
}