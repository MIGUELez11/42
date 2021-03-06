/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:42:52 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/11 17:02:25 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../cub3d.h"
# include "../../minilibx_linux/mlx.h"

/*
** FOV = angle * (M_PI / 180)
** angle 60 = 1.0471975511965976
*/

# ifndef FOV
#  define FOV 1.0471975511965976
# endif

# ifndef DELTATIME
#  define DELTATIME 0.25
# endif

# if OS == 0
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
# elif OS == 1
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LARR 123
#  define RARR 124
#  define ESC 53
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
	int				larr;
	int				rarr;
}					t_keys;

typedef struct		s_ray
{
	double			ray_angle;
	double			wall_hit_x;
	double			wall_hit_y;
	double			distance;
	int				was_hit_vert;
	int				is_ray_facing_down;
	int				is_ray_facing_right;
	double			hwall_hit_x;
	double			hwall_hit_y;
	double			vwall_hit_x;
	double			vwall_hit_y;
	int				found_horz_hit;
	int				found_vert_hit;
	double			xstep;
	double			ystep;
	double			xintercept;
	double			yintercept;
	double			correct_distance;
	int				wall_type;
	int				hit_type;
	int				v_hit_type;
	int				h_hit_type;
	double			wall_strip_height;
}					t_ray;

typedef struct		s_mlx_config
{
	t_cub_config	*cub_cfg;
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		*player;
	t_ray			**rays;
	t_ray			*ray;
	t_img			img;
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	t_img			sprite;
	t_keys			keys;
	float			time;
	unsigned int	color;
}					t_mlx_config;

void				clear_mlx_config(t_mlx_config *config);
int					mlx_exit(void *config);
void				generate_window(t_mlx_config *config);
void				set_event_listeners(t_mlx_config *config);
void				player_controller(t_mlx_config *cfg);
void				player_move(t_mlx_config *cfg, int direction);
void				player_strafe(t_mlx_config *cfg, int direction);
void				player_rotate(t_mlx_config *cfg, int direction);
char				cub_map(t_mlx_config *cfg, int x, int y);

void				put_color_to_pixel(t_coords coords,
					t_img *img, t_mlx_config *cfg);
void				get_color_from_pixel(t_coords coords,
					t_img *img, t_mlx_config *cfg);

void				paint_walls(t_mlx_config *cfg);

/*
** Defining rays.c functions
*/

t_ray				*new_ray(double ray_angle);
void				ray_cast(t_ray *ray, t_mlx_config *cfg, int wall_type);

/*
** Defining rays2.c functions
*/

void				ray_cast_loopv(t_ray *ray, double next_vert_touch_x,
					double next_vert_touch_y, t_mlx_config *cfg);
void				ray_cast_looph(t_ray *ray, double next_horz_touch_x,
					double next_horz_touch_y, t_mlx_config *cfg);

/*
** Defining map.c functions
*/

int					map_check(t_mlx_config *cfg, double dx, double dy);

/*
** Defining vectors.c functions
*/

double				vector_distance(t_coords a, t_coords b);
t_coords			vector_unit(t_coords v);
double				vector_angle(t_coords r, t_coords s);
double				rad_deg(double angle, char *unit);
t_coords			normalize_coord(t_coords coord);
t_coords			vector_2points(t_coords p, t_coords q);
t_coords			vector_perp(t_coords v);
double				normalize_angle(double angle);

/*
** Defining graphic_control.c
*/

void				initialize_graphics(t_mlx_config *cfg);
void				draw_walls(t_mlx_config *cfg);
void				draw_objects(t_mlx_config *cfg);

/*
** Defining draw.c
*/

void				draw_wall(t_coords a, t_coords b, t_img *img,
					t_mlx_config *cfg);
void				draw_line(t_coords a, t_coords b, t_img *img,
					t_mlx_config *cfg);

/*
** Defining image.c
*/

t_img				create_image_from_file(char *filename, t_mlx_config *cfg);
t_img				create_image(int w, int h, t_mlx_config *cfg);
void				pick_color(t_ray *ray, t_coords coords,
					t_coords coords2, t_mlx_config *cfg);

/*
** Defining math.c
*/

double				rem(double a, double b);
int					rgba_to_hex(int rgb[3]);
int					get_hex_from_pixel(char a, char r, char g, char b);

/*
** Defining save_image.c
*/

int					save_bmp(t_mlx_config *cfg);

#endif
