/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_linear_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:55 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/20 07:01:44 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	scalar_multiplication(t_coord *result, t_coord *vector, float lambda)
{
	result->x = vector->x * lambda;
	result->y = vector->y * lambda;
	result->z = vector->z * lambda;
}

void	vector_addition(t_coord *result, t_coord *a, t_coord *b)
{
	if (result == NULL || a == NULL || b == NULL)
		return ;
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
}

void	vector_subtraction(t_coord *result, t_coord *a, t_coord *b)
{
	if (result == NULL || a == NULL || b == NULL)
		return ;
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
}
