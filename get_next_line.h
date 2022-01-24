#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#  define BUFFER_SIZE 2

int		get_next_line(int const fd, char **line);
int		ft_strlen(const char *s);
char	*ft_join(char const *s1, char const *s2);
char	*ft_stock(char *s);
int		is_eol(const char *str);
char	*ft_line(const char *s1);
int		ft_countbeforen(const char *str);

#endif
