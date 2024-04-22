/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_readfloat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:30:52 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:38:27 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
void	parser_skipspacesifnotspaceerror(t_parser *p)
{
	if (!ft_isspace(p->str[p->i]))
		parser_error(1, p);
	parser_skipspaces(p->str, &(p->i));
}

static float	parser_readfloat_getfractionalpart(char *s, int i)
{
	float	nb;
	int		tmp;

	tmp = 0;
	nb = 0;
	while (tmp < 6 && s[i] >= '0' && s[i] <= '9')
	{
		nb = 10 * nb + s[i++] - '0';
		tmp ++;
	}
	while (tmp)
	{
		nb /= 10;
		tmp --;
	}
	return (nb);
}

static int	parser_readfloat_getsign(t_parser *p)
{
	int	res;

	if (p->str[p->i] == '-')
		res = -1;
	else
		res = 1;
	if (p->str[p->i] == '-' || p->str[p->i] == '+')
		(p->i)++;
	return (res);
}

float	parser_readfloat(t_parser *p)
{
	float	res;
	float	tmp1;
	int		sign;

	if (!(ft_isdigit(p->str[p->i]) || ((p->str[p->i] == '-' || p->str[p->i] == '+')
				&& ft_isdigit(p->str[p->i + 1]))))
		parser_error(1, p);
	res = (float) ft_atoi(p->str + (p->i));
	sign = parser_readfloat_getsign(p);
	while (p->str[p->i] && ft_isdigit(p->str[p->i]))
		(p->i)++;
	if (p->str[p->i] != '.')
		return (res);
	else if (p->str[p->i] == '.' && !ft_isdigit(p->str[(p->i) + 1]))
		parser_error(1, p);
	(p->i)++;
	tmp1 = parser_readfloat_getfractionalpart(p->str, p->i);
	while (p->str[p->i] && ft_isdigit(p->str[p->i]))
		(p->i)++;
	if (sign == 1)
		return (res + tmp1);
	return (res - tmp1);
}
