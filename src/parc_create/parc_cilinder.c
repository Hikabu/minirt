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


typedef enum e_object_id
{
	id_unset,
	id_ambient,
	id_light,
	id_camera,
	id_plane,
	id_cylinder,
	id_cone,
	id_sphere,
	id_triangle,
	id_torus
}	t_obj_id;


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



int	parse_camera(t_entire *ent, char *line, int i)
{
	char		**params;
	t_camera	camera;

	params = ft_split(line, ' ');
	// if (ent->camera.id)
	//	return (show_parsing_error(rt, params, ERR_TOO_MANY_CAMERAS));
	//if (array_length(params) != 4)
	//	return (show_parsing_error(rt, params, ERR_INVALID_NB_PARAMS));
	ft_bzero(&camera, sizeof(t_camera));
	camera.id = id_camera;
	while (params && params[++i])
	{
		// ent->pnum = i;
		if (i == 1 && parse_vector(params[i], &camera.norm_vec))
			// return (show_parsing_error(ent, params, ERR_INVALID_NB_COORDS));
		if (i == 2 && parse_vector(params[i], &camera.norm_vec))
			// return (show_parsing_error(ent, params, ERR_INVALID_NB_ORIENT));
		if (i == 3 && parse_ulong(params[i], &camera.fov))
			// return (show_parsing_error(ent, params, ERR_NOT_A_ULONG));
	}

	vec_normalize(&camera.norm_vec);
	ent->camera = &camera;
	free_array(params);
	return (0);
}




int	parse_params(t_entire *ent, char *line)
{
	if (ft_strncmp(line, "A", 1) == 0)
		//
	if (ft_strncmp(line, "C", 1) == 0)
		//
	if (ft_strncmp(line, "L", 1) == 0)
		//
	if (ft_strncmp(line, "sp", 2) == 0)
		//
	if (ft_strncmp(line, "pl", 2) == 0)
		//
	if (ft_strncmp(line, "cy", 2) == 0)
		//
	return (0);
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