#include "get_next_line.h"

char		*ft_line(char *s1)
{
	size_t	i;
	char	*dest;
	int	search;

	search = ft_countbeforen(s1);
	i = 0;
	dest = malloc(sizeof(char) * search + 1);
	if (!dest)
		return (NULL);
	if (s1)
	{
		while (s1[i] && s1[i] != '\n')
		{
			dest[i] = s1[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

int			is_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_stock(char *s)
{
	int		i;
	int		search;

	if (!s)
		return (0);
	search = ft_countbeforen(s);
	if (!s[search])
	{
		free(s);
		return (0);
	}
	if (s && s[search])
		search++;
	i = 0;
	while (s && s[search])
	{
		s[i] = s[search];
		i++;
		search++;
	}
	s[i] = '\0';
	return (s);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	static char	*save[1024];
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((!is_return(save[fd]))
		&& ((reader = read(fd, buff, BUFFER_SIZE)) != 0))
	{
		if (reader == -1)
			return (-1);
		buff[reader] = '\0';
		temp = save[fd];
		save[fd] = ft_join(save[fd], buff);
		free(temp);
	}
	*line = ft_line(save[fd]);
	save[fd] = ft_stock(save[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
int main()
{
    char *line;
    int fd;

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("1. %s\n", line);
    get_next_line(fd, &line);
    printf("2. %s\n", line);
    get_next_line(fd, &line);
    printf("3. %s\n", line);
    get_next_line(fd, &line);
    printf("4. %s\n", line);
}
