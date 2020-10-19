/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:42:52 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/19 21:30:04 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../cub3d.h"
# include "../../minilibx/mlx.h"

# ifndef GRID
#  define GRID 32
# endif
# ifndef DELTATIME
#  define DELTATIME 0.0166
# endif

typedef struct		s_img
{
	void			*ptr;
	char			*buff;
	int				w;
	int				h;
	int				bpp;
	int				line_size;
	int				endian;
}					t_img;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
}					t_keys;

typedef struct		s_mlx_config
{
	t_cub_config	*cub_cfg;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_keys			keys;
	float			time;
}					t_mlx_config;

void				clear_mlx_config(t_mlx_config *config);
int					mlx_exit(void *config);
void				generate_window(t_mlx_config *config);
void				set_event_listeners(t_mlx_config *config);
void				initialize_graphics(t_mlx_config *cfg);
void				player_controller(t_mlx_config *cnf);
void				player_move(t_mlx_config *cnf, int direction);
void				player_rotate(t_mlx_config *cnf, int direction);
char				cub_map(t_mlx_config *cnf, int x, int y);

void				put_color_to_pixel(t_coords coords, int color,
t_img *img, void *mlx_p);

double				vector_distance(t_coords a, t_coords b);
t_coords			vector_unit(t_coords v);
double				vector_angle(t_coords r, t_coords s);
double				rad_deg(double angle, char *unit);
t_coords			normalize_coord(t_coords coord);
t_coords			vector_2points(t_coords p, t_coords q);
t_coords			vector_perp(t_coords v);

void				paint_walls(t_mlx_config *cfg);
unsigned long		rgba_to_hex(int rgb[3]);

#endif
