/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:29:14 by vfedorov          #+#    #+#             */
/*   Updated: 2024/01/25 10:13:24 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{	
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

void	ft_lstadd_back_amlight(t_amlight **lst, t_amlight *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_camera(t_camera **lst, t_camera *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_light(t_light **lst, t_light *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_plane(t_plane **lst, t_plane *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}
