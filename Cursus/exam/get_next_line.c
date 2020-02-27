#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define BUFFER_SIZE 9999

size_t	ft_strlen(char *str)
{
	size_t i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	i = 0;
	char	*ret;
	if (!str)
		return (NULL);
	ret = malloc((len > ft_strlen(str) ? ft_strlen(str) : len)+ 1);
	if (!ret)
		return (NULL);
	while (str[start + i] && i < len)
	{
		ret[i] = str[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char *str3 = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	size_t i = 0;
	size_t j = 0;

	if (!str3)
		return (NULL);
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	str3[i + j] = 0;
	return (str3);
}

int		pf_reader(char **static_buffer)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = read(0, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (-1);
	buffer[bytes] = 0;
	temp = ft_strjoin(*static_buffer, buffer);
	if (!temp)
		return (-1);
	free(*static_buffer);
	free(buffer);
	*static_buffer = temp;
	return (bytes);
}

ssize_t	find_n(char *buffer) {
	ssize_t	i = 0;

	if (!buffer)
		return (-2);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
		return (-1);
	return (i);
}

int		get_line(char **buffer, char **line)
{
	char	*temp;
	ssize_t	npos = find_n(*buffer);

	if (npos == -2)
		return (-1);
	//printf("str = \"%s\"\n", *buffer);
	*line = ft_substr(*buffer, 0, npos);
	if (!*line)
		return (-1);
	//printf("line = \"%s\"\n", *line);
	temp = ft_substr(*buffer, npos + 1, ft_strlen(*buffer));
	if (!temp)
	{
		free(*line);
		return (-1);
	}
	free(*buffer);
	*buffer = temp;
	return (1);
}

int		get_next_line(char **line)
{
	static char	*buffer;
	ssize_t		bytes;
	ssize_t		npos = -1;

	if (!line)
		return (-1);
	if (!buffer)
		buffer = ft_substr("", 0, 0);
	if (find_n(buffer) >= 0)
		return (get_line(&buffer, line));
	while (npos == -1)
	{
		bytes = pf_reader(&buffer);
		if (bytes == -1)
			return (-1);
		npos = find_n(buffer);
		if (npos == -2)
			return (-1);
		if (npos >= 0 && bytes > 0)
			return (get_line(&buffer, line));
		else if (npos == -1 && bytes == 0)
		{
			*line = buffer;
			return (0);
		}
	}
	return (-1); 
}
/*
int main()
{
	char	*str;
	int		ret;


	while ((ret = get_next_line(&str)) == 1)
	{
		printf("\"%s\"\n", str);
		free(str);
	}
	if (ret == 0)
	{
		printf("\"%s\"\n", str);
		free(str);
	}
}
*/
