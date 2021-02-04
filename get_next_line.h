#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//#define BUFFER_SIZE 78
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int const fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr_and_cpy(char *s, int c);
int		is_return(char *str);
char	*ft_strdup(char *s1);

#endif
