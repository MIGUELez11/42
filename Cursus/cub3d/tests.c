#include "minilibx/mlx.h"
#include "src/cub3d.h"

int	main()
{
	char	**a;

	a = malloc(sizeof(char *) * 2);
	a[0] = malloc(sizeof(char) * 5);
	a[0][0] = 'H';
	a[0][1] = 'o';
	a[0][2] = 'l';
	a[0][3] = 'a';
	a[0][4] = '\0';
	a[1] = malloc(sizeof(char) * 2);
	a[1][0] = '0';
	a[1][1] = '\0';

	ft_printf("a[0] = %s a[2][3]%c", a[0], a[1][29]);
}