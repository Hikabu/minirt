/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:25:06 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/22 14:34:01 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "minirt.h"
# include "scene.h"
typedef struct s_parser
{
	t_scene	*scene;
	int		readelem;
	char	*str;
	int		i;
	int		file_fd;
}	t_parser;

t_scene	*parser_createscene(t_parser *p);
int		ft_isspace(char c);

void	parser_skipspaces(char *s, int *i);
void	parser_error(int exitcode, t_parser *parser);
float	parser_readfloat(t_parser *parser);
int		parser_readcolor(t_parser *parser);
t_coord	parser_readcoord(t_parser *parser);

void	parser_readambient(t_parser *parser);
void	parser_readcamera(t_parser *parser);
void	parser_readlight(t_parser *parser);
void	get_fov_angles(t_scene *data);

void	free_scene(t_scene *scene);

void	parser_skipspacesifnotspaceerror(t_parser *parser);
float	parser_readfloat(t_parser *parser);

void	parser_readsphere(t_parser *parser);

void	parser_check_isnotnormailzed(t_parser *parser, t_coord vect);
void	parser_readplane(t_parser *parser);

void	parser_readcylinder(t_parser *parser);

void	parser_fill_color_ambient(t_parser *parser);

void	rotate_objects(t_scene *scene, t_coord *coord);
void	translate_objects(t_scene *scene, t_coord *coord);

#endif
