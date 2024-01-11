#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
#include <unistd.h>

// static int  verify_line(char **stack, char **line);
char        *ft_substr(char const *s, unsigned int start, size_t len);
size_t	    ft_strlen(const char *str);
char        *ft_strdup(const char *s1);
char	    *ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int i);
char 		*get_next_line(int fd);
void        *ft_free(char **s);

//static char	*extract(char *line);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4

#endif
