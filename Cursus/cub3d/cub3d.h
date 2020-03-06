#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf/functions/ft_printf.h"
# include <minilibx/mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_args
{
	void	*window;
	void	*mlx;
}				t_args;

void			cb_destroy_window(t_args *args);
int				cb_onKeypress(int keycode, t_args *args);
int				cb_onKeyrelease(int keycode, t_args *args);

#endif
