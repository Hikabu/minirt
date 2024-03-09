/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/09 18:58:45 by vfedorov         ###   ########.fr       */
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

// int	parc(char *line, t_entire **ent, t_data *data)
// {
// 	int			i;
// 	char		**str;
// 	i = -1;
// 	while (line && line[++i])
// 		if (line[i] == '\t' || line[i] == '\n')
// 			line[i] = ' ';
// 	str = ft_split(line, ' ');
// 	initial_scene(data->scene);
// 	get_fov_angles(data->scene);
// 	// parse_params(ent, str);
// 	free_split(str);
// 	return (0);
// }
