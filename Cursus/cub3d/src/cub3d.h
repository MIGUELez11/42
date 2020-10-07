/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:39:50 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/06 10:42:28 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct	s_player
{
	int			x;
	int			y;
	char		facing;
}				t_player;

typedef struct	s_cub_config
{
	t_list		*lst_map;
	int			resolution[2];
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

void			print_config(t_cub_config *config);

#endif
