/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:39:50 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/19 21:57:57 by mflorido         ###   ########.fr       */
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
	t_coords	direction;
	t_coords	velocity;
	t_coords	camerapos;
	t_coords	cameradir;
	double		heading;
	int			heading_set;
}				t_player;

typedef struct	s_cub_config
{
	t_list		*lst_map;
	int			map_height;
	int			width;
	int			height;
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
