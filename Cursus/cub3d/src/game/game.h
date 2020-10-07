/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:42:52 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/07 11:48:46 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../cub3d.h"
# include "../../minilibx/mlx.h"

typedef struct		s_mlx_config
{
	t_cub_config	*cub_config;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx_config;

void				clear_mlx_config(t_mlx_config *config);
int					mlx_exit(void *config);
void				generate_window(t_mlx_config *config);
void				set_event_listeners(t_mlx_config *config);

#endif
