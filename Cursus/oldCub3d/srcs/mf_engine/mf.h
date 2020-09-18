#include "../../minilibx/mlx.h"

typedef struct	s_windowprops
{
	int		x;
	int		y;
	int		max_x;
	int		max_y;
	char	name[25];
}				t_windowprops;

typedef struct	s_args
{
	void			*window;
	void			*mlx;
	int				max_x;
	int				max_y;
	t_windowprops	windowP;
	int				(*KeyPress)(int, struct s_args *);
	int				(*KeyRelease)(int, struct s_args *);
	int				(*MouseMove)(int, int, struct s_args *);
	int				(*Exit)(struct s_args *);
	int				(*Main)(struct s_args *);

}				t_args;

void			mf_new_window(t_args *args, int x, int y, char *name);
void			mf_trigger_keys(t_args *args);
void			mf_trigger_mouse(t_args *args);
void			mf_start(t_args *args);
