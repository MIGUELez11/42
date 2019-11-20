
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char **line;

	argc++;
	fd = open(argv[1], O_RDWR);
	line = malloc(sizeof(char *));
	get_next_line(fd, line);
	printf("%s", *line);
}
