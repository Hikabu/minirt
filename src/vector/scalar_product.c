/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:44 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:32:45 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "vector.h"

/* Возвращает результат скалярного умножения двух векторов */
float	scalar_product_2_vectors(t_coord *a, t_coord *b)
{
	float	result;

	result = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (result);
}

/* Возвращает угол между двумя векторами */
float	angle_between_2_vectors(t_coord *a, t_coord *b)
{
	float	angle;

	angle = scalar_product_2_vectors(a, b)
		/ (vector_length(a) * vector_length(b));
	return (angle);
}
