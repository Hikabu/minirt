/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:35:23 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:35:24 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct s_coord	t_coord;

/*  scalar_product.c
	Скалярное умножение векторов */
float	scalar_product_2_vectors(t_coord *a, t_coord *b);
float	angle_between_2_vectors(t_coord *a, t_coord *b);

/*  vector_create.c
	Create a new vector, matrices */
void	vector_multiplication(t_coord *res, t_coord *vec1, t_coord *vec2);
void	new_vector(t_coord *result, float x, float y, float z);
void	new_vector_by_two_points(t_coord *result, t_coord *a, t_coord *b);

/*  vector_length_normalizing.c
	Calculate vector length and normalizing vector */
float	vector_length(t_coord *vector);
float	vector_length_by_two_points(t_coord *a, t_coord *b);
void	normalizing_vector(t_coord *result, t_coord *vector);

/*  print_vector.h
	Print to stdout vectors and matrices */
void	print_vector(char *name, t_coord *vector);

/*  vector_linear_operations.c 
	Scalar multiplication*/
void	scalar_multiplication(t_coord *result, t_coord *vector, float lambda);
void	vector_addition(t_coord *result, t_coord *a, t_coord *b);
void	vector_subtraction(t_coord *result, t_coord *a, t_coord *b);

#endif
