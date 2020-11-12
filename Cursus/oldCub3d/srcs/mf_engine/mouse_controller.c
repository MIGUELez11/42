#include "mf.h"

void	mf_trigger_mouse(t_args *args)
{
	mlx_hook(args->window, 6, 0, args->MouseMove, args);
}
