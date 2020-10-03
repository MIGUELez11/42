/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:39:50 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/03 14:35:02 by mflorido         ###   ########.fr       */
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

void			get_cub_config(int fd);
int				validate_cub_file(char *filename);
void			clear_cub_config(t_cub_config *config);
void			set_sprites(char *position, char *value, t_cub_config *config);
void			set_colors(char *position, char *value, t_cub_config *config);
void			setup_config(t_cub_config *config);
void			parse_map(t_cub_config *config);
void			cub_exit(char *msg, int code, t_cub_config *config);

void			print_config(t_cub_config *config);
char			*ft_removeduplicates(const char *str, const char *set);
char			*ft_strremovechar(const char *str, char c);

#endif
