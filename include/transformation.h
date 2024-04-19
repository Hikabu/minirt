/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:35:19 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/19 18:35:20 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

# include "minirt.h"

void	apply_rotation_to_objects(t_coord *cam,
			t_objects *obj, float rotation_matrix[3][3]);

#endif