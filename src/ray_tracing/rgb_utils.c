/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:58:14 by vfedorov          #+#    #+#             */
/*   Updated: 2024/04/03 18:25:55 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// lets watch whart will be 
int	rgb_to_int(const t_color rgb)
{
	return(rgb.r << 16 | rgb.g << 8 | rgb.b);
}

int	parse_color(char *str, t_color *color)
{
	int		i;
	int		ret;
	char	**rgb;

	i = -1;
	ret = 0;
	rgb = ft_split(str, ',');
	while (rgb && rgb[++i])
		if (!is_ulong(rgb[i]))
			ret = 1;
	if (array_length(rgb) != 3)
		ret = 1;
	else
	{
		color->r = (float) str_to_int_color(rgb[0]);
		color->g = (float) str_to_int_color(rgb[1]);
		color->b = (float) str_to_int_color(rgb[2]);
	}
	free_array(rgb);
	return (ret);
}
int	parser_return_color_ambient(int color1, int color2, float intensity)
{
	int	res;

	res = ((int)(intensity
				* (((color1 >> 16 & 255) * (color2 >> 16 & 255)) / 255))) << 16;
	res |= (int)(intensity
			* (((color1 >> 8 & 255) * (color2 >> 8 & 255) / 255))) << 8;
	res |= (int)(intensity
			* (((color1 & 255) * (color2 & 255) / 255)));
	return (res);
}
// t_color	*compute_color_amb(t_color *tmp_color, t_color *amb_col)
// {
// 	tmp_color->r = max(-255 + tmp_color->r + amb_col->r, 0);
// 	tmp_color->g = max(-255 + tmp_color->g + amb_col->g, 0);
// 	tmp_color->b = max(-255 + tmp_color->b + amb_col->b, 0);
// 	return (tmp_color);
// }

