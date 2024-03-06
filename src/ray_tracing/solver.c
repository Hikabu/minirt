/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:59:45 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/05 16:05:27 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	ax^2 + bx + c = 0
*/

static	void put_roots(float roots[2], float root1, float root2)
{
	if (!roots)
		return ;
	roots[0] = root1;
	roots[1] = root2;
}

int	solve_quadro_eq(float a, float b, float c, float roots[2])
{
	float	d_sqare;

	d_sqare = b * b - 4 * a * c; //disriminant 
	if (d_sqare < 0) //no roots 
	{
		put_roots(roots, INFINITY, INFINITY); //from math.h
		return (0);
	}
	if (d_sqare == 0)   // we have one root 
	{
		put_roots(roots, (-b) / (2 * a), (-b) / (2 * a));
		if (roots)
			roots[1] = roots[0];
		return (1);
	}
	put_roots(roots, (-b - sqrt(d_sqare)) / (2 * a),
		(-b + sqrt(d_sqare)) / (2 * a));
	return (2);
}