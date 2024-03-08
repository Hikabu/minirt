/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_cilinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:37:34 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/03/04 21:18:19 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initial_scene(t_scene *scene)
{
	scene->obj = calloc(1, sizeof(t_obj));
	if (!(scene->obj))
		error(1);
	fill_new_vector(&scene->camera_point, 0, 0, 0);
	fill_new_vector(&scene->camera_orientation, 0, 0, 1);
	scene->camera_fov = 90; //default
	scene->ambient_light_intensiv = 1;
	scene->ambient_light_rgb = 0xffffff;
	scene->obj->light = 0;
	scene->obj->cyl = 0;
	scene->obj->sphere = 0;
	scene->obj->plane = 0;
	// printf ("what is in the road %f\n", scene->camera_point.z);
}

char *sanitize_line(const char *line) 
{
    char *result = NULL;
    int i = 0;
	char *trimmed;

    result = malloc(ft_strlen(line) + 1);
    if (!result) 
		return NULL;

    while (line[i] != '\0') 
	{
        if (line[i] == '\t' || line[i] == '\n') 
            result[i] = ' ';
		else 
            result[i] = line[i];
        i++;
    }
    result[i] = '\0';

    trimmed = ft_strtrim(result, " ");
    free(result); 

    return trimmed;
}


int open_and_parse_file(t_entire *ent, const char *path) 
{
	int parse_success;

    int fd = open(path, O_RDONLY);
    if (fd < 0) 
	{
        perror("Error opening file");
        return 0;
    }
    parse_success = parse_scene_file(ent, fd);
    close(fd);

    return parse_success; 
}

int	parse_scene_file(t_entire *ent, int fd)
{
	int		num;
	int		status;
	char	*line;

	num = 0;
	status = 0;
	while (status != 1)
	{
		num++;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = sanitize_line(line);
		//ent->lnum = num;
		if (parse_params(ent, line))
			status = 1;
		free(line);
	}
	//if (!status && is_invalid_file(ent))
	//	status = 1;
	close(fd);
	return (status);
}



int	parse_camera(t_entire *ent, char *line)
{
	char		**params;
	t_camera	camera;
	int i;

	params = ft_split(line, ' ');
	// if (ent->camera.id)
	//	return (show_parsing_error(rt, params, ERR_TOO_MANY_CAMERAS));
	//if (array_length(params) != 4)
	//	return (show_parsing_error(rt, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(&camera, sizeof(t_camera));
	//camera.id = id_camera;
	i = 1;

	while (params && params[i])
	{
		// ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &camera.xyz))
			// return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &camera.norm_vec))
			// return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_ulong(params[i], &camera.fov))
			// return (show_parsing_error(ent, params, ERR_NOT_A_ULONG));
		i++;
	}

	vec_normalize(&camera.norm_vec);
	ent->camera = &camera;
	free_array(params);
	return (0);
}


int	parse_ambient(t_entire *ent, char *line)
{
	int			i;
	char		**params;
	t_amlight	amlight;
	int i;

	params = ft_split(line, ' ');
	//if (rt->ambient.id)
	//	return (show_parsing_error(rt, params, ERR_TOO_MANY_AMBIENTS));
	//if (array_length(params) != 3)
	//	return (show_parsing_error(rt, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(&amlight, sizeof(t_amlight));
	//ambient.id = id_ambient;
	i = 1;
	while (params && params[i])
	{
		//ent->pnum = i;
		if (i == 1 && parse_float(params[i], &amlight.ratio))
		//	return (show_parsing_error(rt, params, ERR_NOT_A_FLOAT));
		if (i == 2 && parse_color(params[i], &amlight.rgb))
		//	return (show_parsing_error(rt, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	ent->amlight = &amlight;
	free_array(params);
	return (0);
}

int	parse_light(t_entire *ent, char *line)
{
	int		i;
	char	**params;
	t_light	light;
	int i;

	ft_bzero(&light, sizeof(t_light));

	params = ft_split(line, ' ');
	//if (array_length(params) != 4)
	//	return (show_parsing_error(ent, params, ERR_INVALID_NB_PARAMS));
	i = 1;
	while (params && params[i])
	{
		//ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &light.xyz))
			//return (show_parsing_error(rt, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_float(params[i], &light.ratio))
			//return (show_parsing_error(rt, params, ERR_NOT_A_FLOAT));
		if (i == 3 && parse_color(params[i], &light.rgb))
			//return (show_parsing_error(rt, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	ent->light = &light;
	free_array(params);
	return (0);
}

int	parse_sphere(t_entire *ent, char *line)
{
	int			i;
	t_sphere	sphere;
	char **params;

	params = ft_split(line, ' ');
	ft_bzero(&sphere, sizeof(t_sphere));
	
	i = 1;
	while (params && params[i])
	{
		//ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &sphere.xyz))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_float(params[i], &sphere.diametr))
			//return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 3 && parse_color(params[i], &sphere.rgb))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}

	ent->sphere = &sphere;
	free_array(params);
	return (0);
}


int	parse_plane(t_entire *ent, char *line)
{
	int		i;
	t_plane	plane;
	char **params;

	params = ft_split(line, ' ');

	i = 1;
	ft_bzero(&plane, sizeof(t_plane));
	while (params && params[i])
	{
		//ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &plane.xyz))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &plane.norm_vec))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_colors(params[i], &plane.rgb))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}
	vec_normalize(&plane.norm_vec);
	ent->plane = &plane;
	free_array(params);
	return (0);
}


int	parse_cylinder(t_entire *ent, char *line)
{
	int			i;
	t_cyl	cylinder;
	char **params;

	params = ft_split(line, ' ');

	i = 1;
	ft_bzero(&cylinder, sizeof(t_cyl));
	while (params && params[i])
	{
		//ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &cylinder.xyz))
			//return (show_parsing_error(rt, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &cylinder.norm_vec))
			//return (show_parsing_error(rt, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_float(params[i], &cylinder.diam))
			//return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 4 && parse_float(params[i], &cylinder.heig))
			//return (show_parsing_error(ent, params, ERR_NOT_A_FLOAT));
		if (i == 5 && parse_colors(params[i], &cylinder.rgb))
			//return (show_parsing_error(ent, params, ERR_INVALID_NB_COLORS));
		i++;
	}	

	vec_normalize(&cylinder.norm_vec);
	ent->cyl = &cylinder;
	free_array(params);
	return (0);
}


typedef struct s_entire
{
	t_amlight	*amlight;
	t_camera	*camera;
	t_scene		*scene;
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
	t_crd		*crd;
}	t_entire;

int	parse_params(t_entire *ent, char *line)
{
	if (ft_strncmp(line, "A", 1) == 0)
		return (parse_ambient(ent, line));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(ent, line));
	if (ft_strncmp(line, "L", 1) == 0)
		return(parse_light(ent, line));
	if (ft_strncmp(line, "sp", 2) == 0)
		return(parse_sphere(ent, line));
	if (ft_strncmp(line, "pl", 2) == 0)
		return(parse_plane(ent, line));
	if (ft_strncmp(line, "cy", 2) == 0)
		return(parse_cylinder(ent, line));
	return (0);
}




int	parse_vector(char *str, t_crd *vect)
{
	int		i;
	int		ret;
	char	**nbrs;

	i = -1;
	ret = 0;
	nbrs = ft_split(str, ',');
	while (nbrs && nbrs[++i])
		//if (!is_float(nbrs[i]))
		//	ret = 1;
	if (array_length(nbrs) != 3)
		ret = 1;
	else
	{
		vect->x = str_to_float(nbrs[0]);
		vect->y = str_to_float(nbrs[1]);
		vect->z = str_to_float(nbrs[2]);
	}
	free_array(nbrs);
	return (ret);
}

int	array_length(char *arr[])
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

float	str_to_float(char *str)
{
	float	sum;
	float	prec;
	float	div;
	float	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
}


int	parse_float(char *str, float *num)
{
	if (!is_float(str))
		return (1);
	*num = str_to_float(str);
	return (0);
}


int	parse_color(char *str, t_color *color)
{
	int		i;
	int		ret;
	char	**rgb;

	i = -1;
	ret = 0;
	rgb = ft_split(str, ',');
	//while (rgb && rgb[++i])
	//	if (!is_ulong(rgb[i]))
	//		ret = 1;
	if (array_length(rgb) != 3)
		ret = 1;
	else
	{
		color->r = (float) str_to_int_color(rgb[0]) / 255;
		color->g = (float) str_to_int_color(rgb[1]) / 255;
		color->b = (float) str_to_int_color(rgb[2]) / 255;
	}
	free_array(rgb);
	return (ret);
}

int	parse_ulong(char *str, size_t *num)
{
	if (!is_ulong(str))
		return (1);
	*num = (size_t)ft_atoi(str);
	return (0);
}