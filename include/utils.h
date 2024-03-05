#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

typedef struct s_ambient_lightning	t_amlight;
typedef struct s_light				t_light;
typedef struct s_plane				t_plane;
typedef struct s_cylinder			t_cyl;
typedef struct s_camera				t_camera;
typedef struct s_sphere				t_sphere;
typedef struct s_entire				t_entire;

void	init_a(t_amlight *list);
void	init_c(t_camera *list);
void	init_l(t_light *list);
void	init_pl(t_plane *list);
void	init_cy(t_cyl *list);
void	init_sp(t_sphere *list);
void	init_ent(t_entire *ent);
#endif