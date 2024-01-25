/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/01/20 01:36:00 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	id_check(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "A"))
	{
		if ((*ent)->amlight != NULL)
		{
			tmp = (*ent)->amlight;
			ft_lstadd_back_amlight(&((*ent)->amlight), to_struct_a(str));
		}
		(*ent)->amlight = to_struct_a(str);
		if (tmp)
			(*ent)->amlight = tmp;
	}
	else
		id_check1(str, ent);
}

void	count_of_split(char **str, int count)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	if (i != count)
		error(1);
}

int	parc(char *line, t_entire **ent)
{
	int			i;
	char		**str;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
	str = ft_split(line, ' ');
	id_check(str, ent);
	return (0);
}
