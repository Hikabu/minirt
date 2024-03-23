#include "minirt.h"

char *sanitize_line(const char *line) 
{
    char *result = NULL;
    int i = 0;
	char *trimmed = NULL;

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

int	parse_scene_file(t_entire *ent, int fd)
{
	int		num;
	int		status;
	char	*line;
	(void)ent;
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
	(void)num;
	return (status);
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
	ent->scene = (t_scene *)malloc(sizeof(t_scene));
	if (!(ent->scene))
		error(1);
	ent->scene->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!(ent->scene->obj))
		error(1);
    parse_success = parse_scene_file(ent, fd);
	initial_scene(ent->scene);
	get_fov_angles(ent->scene);
	translate_obj(ent->scene, &ent->scene->camera_point);
	// rotate_obj(ent->scene, &ent->scene->camera_orientation);
    close(fd);

    return parse_success; 
}

