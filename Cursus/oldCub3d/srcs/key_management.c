#include "cub3d.h"

int		cb_onKeypress(int keycode, t_args *args)
{
	ft_printf("key \e[1;33m%4d\e[0m pressed  on window \e[1;34m%p\e[0m\n", keycode, args->window);
	if (keycode == 53)
	{
//		cb_destroy_window(args);
		args->Exit(args);
	}
	return (1);
}

int		cb_onKeyrelease(int keycode, t_args *args)
{
	ft_printf("key \e[1;33m%4d\e[0m released on window \e[1;34m%p\n\e[0m", keycode, args->window);
	return (1);
}
