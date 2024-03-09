/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:57:40 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/09 19:09:28 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    fill_new_vector(t_crd *result, float x, float y, float z) // take pointer to vector and init it
{
    if (result == NULL)
        return ;
    result->x = x;
    result->y = y;
    result->z = z;  
}

void	vector_subtraction(t_crd *res, t_crd *a, t_crd *b)
{
	if (res == NULL || a == NULL || b == NULL)
		return ;
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
}

float vec_length(t_crd *vec) //find length of vector
{
	float result;
	
	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (result);
}

void norm_vector(t_crd *vec) //normalize vector
{
	float length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

float	vec_product(t_crd *vec1, t_crd *vec2)
{
	float result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (result);
}
float	scalar_vector_product(t_crd *a, t_crd *b) // scalar produc of 2 vectors
{
	float	res;

	res = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (res);
}

// float	scalar_multiplication(t_crd *res, t_crd *vector, float lambda)
// {
// 	res->x = vector->x * lambda;
// 	res->y = vector->y * lambda;
// 	res->z = vector->z * lambda;
// 	return (res);
// }