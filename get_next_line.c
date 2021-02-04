#include "get_next_line.h"

char		*ft_strdup(char *s1)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		dest[i] = s1[i];
		i++;
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

char		*ft_strchr_and_cpy(char *s, int c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s)
	{
		free(s);
		return (0);
	}
	while (s[i] && s[i] != c)
		i++;
	if (!(str = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (NULL);
	if (s[i])
		i++;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	free(s);
	str[j] = '\0';
	return (str);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save[2000];
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_return(save[fd]) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[reader] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	*line = ft_strdup(save[fd]);
	save[fd] = ft_strchr_and_cpy(save[fd], '\n');
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
