/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:25:18 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/09 20:52:38 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	readmap(char *str, t_entire **ent, t_data *data)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(str, O_RDONLY);
// 	if (fd < 0)
// 		error(1);
// 	line = get_next_line(fd);
// 	if (line == NULL || line[0] == '\0')
// 		error(1);
// 	while (line)
// 	{
// 		if (line[0] == '#')
// 		{}
// 		else if (line[0] != '\n')
// 			parc(line, ent, data);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }
