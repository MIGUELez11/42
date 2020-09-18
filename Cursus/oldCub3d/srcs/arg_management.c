#include "cub3d.h"

void    argument_parser(t_args *args, char **argv, int argc) {
	argc++;
	args++;
    char *str = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
    if (!strncmp(str, ".cub", 4))
    {
        free(str);
    }
    free(str);
}
