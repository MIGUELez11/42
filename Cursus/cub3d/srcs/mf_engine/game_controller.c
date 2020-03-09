#include "mf.h"

void	mf_start(t_args	*args)
{
	args->mlx = mlx_init(args);
	if (!args->mlx)
		return ;
	mf_new_window(args, args->windowP.x, args->windowP.y, args->windowP.name);
	mf_trigger_keys(args);
	mf_trigger_mouse(args);
	mlx_loop_hook(args->mlx, args->Main, args);
	mlx_loop(args->mlx);	
}
