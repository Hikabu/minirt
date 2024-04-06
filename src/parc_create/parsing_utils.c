#include "minirt.h"

float	str_to_float(char *str); 
int	is_float(char *str);

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
int	str_to_int_color(char *str)
{
	int	c;

	c = ft_atoi(str);
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}


int	array_length(char *arr[])
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	// printf ("i is %d\n", i);
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

int	is_float(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != '-' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}


int is_ulong(char *str)
{
 int i;
 i = 0; while (str[i] && str[i])
 {  if (ft_isdigit(str[i]) != 1)
   return (0);  i++;
 } return (1);
}

int	parse_ulong(char *str, size_t *num)
{
	if (!is_ulong(str))
		return (1);
	*num = (size_t)ft_atoi(str);
	return (0);
}

void	free_array(char *arr[])
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
