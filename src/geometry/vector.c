/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:57:40 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/05 17:56:32 by vfedorov         ###   ########.fr       */
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

void	vector_multiplication(t_crd *res, t_crd *vec1, t_crd *vec2)
{
	t_crd	res2;

	if (!res || !vec1 || !vec2)
		return ;
	res2.x = vec1->y * vec2->z - vec1->z * vec2->y;
	res2.y = vec1->x * vec2->z - vec1->z * vec2->x;
	res2.z = vec1->x * vec2->y - vec1->y * vec2->x;
	*res = res2;
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

float	vector_len(t_crd *vector)
{
	float	lenght;

	if (!vector)
		return (0);
	lenght	= sqrtf(vector->x * vector->x + vector->y * vector->y
		+ vector->z * vector->z);
	return (lenght);
}
float	ang_bet_2_vec(t_crd *a, t_crd *b)
{
	float	angle;

	angle = scalar_vector_product(a, b)
		/ (vector_len(a) * vector_len(b));
	return (angle);
}
void	scalar_multiplication(t_crd *result, t_crd *vector, float lambda)
{
	result->x = vector->x * lambda;
	result->y = vector->y * lambda;
	result->z = vector->z * lambda;
}

void	vector_addition(t_crd *result, t_crd *a, t_crd *b)
{
	if (result == NULL || a == NULL || b == NULL)
		return ;
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
}