#include "minirt.h"

int	show_parsing_error(t_entire *ent, char **arr, char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	/*if (ent->lnum)
	{
		ft_putstr_fd(" [line:", 2);
		ft_putnbr_fd(ent->lnum, 2);
		ft_putstr_fd(":param:", 2);
		ft_putnbr_fd(ent->pnum + 1, 2);
		ft_putstr_fd("]", 2);
	} */
	ft_putendl_fd("", 2);
	free_array(arr);
	return (1);
}

int	show_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd("", 2);
	return (1);
}