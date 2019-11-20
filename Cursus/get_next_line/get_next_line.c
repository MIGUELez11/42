
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char *buff;
	int i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	read(fd, buff, BUFFER_SIZE);
	while (buff[i] && buff[i] != '\n')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	if (!(line[0]))
	{
		free(buff);
		return (-1);
	}
	while (i >= 0)
	{
		line[0][i] = buff[i];
		i--;
	}
	free(buff);
	return (0);
}
