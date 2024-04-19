/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:59 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:33:00 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "vector.h"

/* 	Вывод на stdout вектора vector, опционально с именем вектора name */
void	print_vector(char *name, t_coord *vector)
{
	if (vector == NULL)
		return ;
	if (name)
		printf("%s=(%f, %f, %f)\n", name, vector->x, vector->y, vector->z);
	else
		printf("(%f, %f, %f)\n", vector->x, vector->y, vector->z);
	return ;
}
