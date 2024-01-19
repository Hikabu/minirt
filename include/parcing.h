#ifndef PARCING_H
# define PARCING_H

typedef struct s_ambient_lightning
{
	int		id;
	float	ratio;
	int		rgb[3];
	void	*next;
}	t_amlight;

typedef struct s_camera
{
	int		id;
	float	xyz[3];
	float	norm_vec[3];
	int		fov;
	void	*next;
}	t_camera;

typedef struct s_light
{
	int		id;
	float	xyz[3];
	float	ratio;
	int		rgb[3];
	void	*next;
}	t_light;

typedef struct s_plane
{
	int		id;
	float	xyz[3];
	float	norm_vec[3];
	int		rgb[3];
	void	*next;
}	t_plane;

typedef struct s_cylinder
{
	int		id;
	float	xyz[3];
	float	norm_vec[3];
	float	diam;
	float	heig;
	int		rgb[3];
	void	*next;
}	t_cyl;

typedef struct s_sphere
{
	int		id;
	float	xyz[3];
	float	diametr;
	int		rgb[3];
	void	*next;
}	t_sphere;

void	error(int er);

int	parc(char *line);
int a_ligth(char *str);
int readmap(char *str);


#endif