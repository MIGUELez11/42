#include "../cub3d.h"

void	cb_destroy_window(t_args *args)
{
	if (args->mlx && args->window)
	{
		mlx_destroy_window(args->mlx, args->window);
		ft_printf("window \e[1;31m%p\e[0m closed\n", args->window);
		args->window = 0;
	}
}
