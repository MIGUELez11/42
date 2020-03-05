#include "ft_printf/functions/ft_printf.h"
#include <minilibx/mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_args {
	void	*window;
	void	*mlx_ptr;
}				t_args;

int		ft_keypress(int keycode, t_args args)
{
	printf("key pressed = %d on %p\n", keycode, args.window);
	if (keycode == 53)
	{
		mlx_destroy_window(args.mlx_ptr, args.window);
		exit(0);
	}
	
	return (1);
}
int		ft_keyrelease(int keycode, t_args args)
{
	printf("key released = %d on %p\n", keycode, args.window);
	return (1);
}
void	check_key(t_args args)
{
	mlx_hook(args.window, 2, 1L<<0, ft_keypress, &args);
	mlx_hook(args.window, 3, 1L<<1, ft_keyrelease, &args);
}
int main()
{
	t_args args;

	args.mlx_ptr = mlx_init();
	args.window = mlx_new_window(args.mlx_ptr, 500, 500, "cub3d");
	check_key(args);
	mlx_loop(args.mlx_ptr);

}
