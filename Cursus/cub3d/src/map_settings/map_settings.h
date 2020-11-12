/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:43:49 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/16 12:33:04 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SETTINGS_H
# define MAP_SETTINGS_H

# include "../cub3d.h"

typedef struct	s_int_coords
{
	int			x;
	int			y;
}				t_int_coords;

void			get_cub_config(int fd, t_cub_config *config);
void			clear_cub_config(t_cub_config *config);
void			set_sprites(char *position, char *value, t_cub_config *config);
void			set_colors(char *position, char *value, t_cub_config *config);
void			setup_config(t_cub_config *config);
void			parse_map(t_cub_config *config);

char			*ft_removeduplicates(const char *str, const char *set);
char			*ft_strremovechar(const char *str, char c);

#endif
