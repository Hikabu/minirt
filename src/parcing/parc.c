/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/13 11:29:36 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	count_of_split(char **str, int count)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	if (i != count)
		error(1);
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}
