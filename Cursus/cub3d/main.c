#include "ft_printf/functions/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    char    *line;
    int     fd;

    argc++;
    int ok;
    fd = open(argv[1], O_RDONLY);
    while ((ok = get_next_line(fd, &line)) == 1) {
        ft_printf("%s\n", line);
        free(line);
    }
    if (ok)
    {
        ft_printf("%s", line);
        free(line);
    }
    ft_printf("%s", line);
}