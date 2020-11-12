#include "mf.h"

void	mf_new_window(t_args *args, int x, int y, char *name)
{
//	mlx_get_screen_size(args->mlx, &args->max_x, &args->max_y);
	args->max_x = 500;
	args->max_y = 500;
	if (x > args->max_x)
		x = args->max_x;
	if (y > args->max_y)
		y = args->max_y;
	if (args->mlx)
		args->window = mlx_new_window(args->mlx, x, y, name);
	if (args->window)
	{
		args->windowP.x = x;
		args->windowP.y = y;
	}
}
