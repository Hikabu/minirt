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
		// printf("_______%s_______\n", line);
		free(line);
	}
	//if (!status && is_invalid_file(ent))
	//	status = 1;
	(void)num;
	close(fd);
	return (status);
}

int open_and_parse_file(t_entire *ent, char *path)
{
	int	parse_success;
	// ent  = (t_entire *)malloc(sizeof(t_entire));
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 0;
	}
	if (!is_rt_file(path))
		return (!show_error("isn't a rt file"));

	ent->scene = (t_scene *)malloc(sizeof(t_scene));
	if (!(ent->scene))
		error(1);
	ent->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!(ent->obj)) // and also check ent->obj
		error(1);
	initial_scene(ent);
	parse_success = parse_scene_file(ent, fd);
	get_fov_angles(ent, ent->scene);
	// translate_obj(ent->scene, &ent->scene->camera_point);
	//  rotate_obj(ent->scene, &ent->scene->camera_orientation);
	close(fd);
	return parse_success;
}

int	is_rt_file(char *path)
{
	int	len;

	len = ft_strlen(path) - 3;
	if (len > 0)
		return (ft_strncmp(path + len, ".rt", 3) == 0);
	return (0);
}
