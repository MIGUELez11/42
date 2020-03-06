#include "cub3d.h"

void	check_key(t_args *args)
{
	mlx_hook(args->window, 2, 1L<<0, cb_onKeypress, args);
	mlx_hook(args->window, 3, 1L<<1, cb_onKeyrelease, args);
}
int main()
{
	t_args args;

	if (!(args.mlx = mlx_init()) || !(args.window = mlx_new_window(args.mlx, 500, 500, "cub3d")))
		ft_printf("\e[1;31mWindow can´t be opened\e[0m\n");
	else
		ft_printf("window \e[1;32m%p \e[0mlaunched\n", args.window);
	check_key(&args);
	mlx_loop(args.mlx);

}
