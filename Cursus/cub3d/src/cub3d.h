/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:39:50 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/02 12:05:29 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef SCREEN_MAX_X
#  define SCREEN_MAX_X 0
# endif

# ifndef SCREEN_MAX_Y
#  define SCREEN_MAX_Y 0
# endif

# ifndef GRID
#  define GRID 64
# endif

# ifndef OS

/*
** linux -> 0
** macos -> 1
*/

#  define OS 1
# endif

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_coords
{
	double		x;
	double		y;
}				t_coords;

typedef struct	s_player
{
	t_coords	position;
	t_coords	velocity;
	double		rotation_speed;
	double		heading;
	int			heading_set;
}				t_player;

typedef struct	s_cub_config
{
	t_list		*lst_map;
	int			map_height;
	int			map_width;
	int			width;
	int			height;
	int			max_x;
	int			max_y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor[3];
	int			ceiling[3];
	int			floor_set;
	int			ceiling_set;
	int			resolution_set;
	char		**map;
	t_player	player;
}				t_cub_config;

int				validate_cub_file(char *filename, t_cub_config *config);
void			cub_exit(char *msg, int code, t_cub_config *config);
void			initialize(t_cub_config *cub_config);
int				check_extension(char *filename, char *match);

void			print_config(t_cub_config *config);

#endif
