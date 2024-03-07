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

    return parse_success; // 1 on success, 0 on failure
}


int parse_scene_file(t_entire *ent, int fd) 
{
    char *line = NULL;
    int line_num = 0;
    int parse_status = 1;
	char *sanitized_line;

    while (get_next_line(fd, &line) > 0) 
	{
        sanitized_line = sanitize_line(line);
        // env->lnum = ++line_num;
        if (!parse_params(ent, sanitized_line)) {
            parse_status = 0;
            free(sanitized_line);
            break;
        }
        free(line); // Free the original line buffer
        free(sanitized_line); // Free the sanitized line
    }
    free(line); // Ensure no leaks in case of EOF
    return parse_status; // Returns 1 on success, 0 on failure
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


