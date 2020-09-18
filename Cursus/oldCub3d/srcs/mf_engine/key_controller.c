#include "mf.h"

void	mf_trigger_keys(t_args *args)
{
	mlx_hook(args->window, 17, 0, args->Exit, args);
	mlx_hook(args->window, 2, 1L<<0, args->KeyPress, args);
	mlx_hook(args->window, 3, 1L<<1, args->KeyRelease, args);
}
