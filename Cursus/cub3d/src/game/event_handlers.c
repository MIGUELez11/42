/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:41:10 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/03 21:35:58 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		mlx_exit(void *config)
{
	if (config)
	{
		clear_mlx_config(config);
		cub_exit("", 0, ((t_mlx_config *)config)->cub_cfg);
	}
	cub_exit("", 0, NULL);
	return (1);
}

int		release_key(int keycode, t_mlx_config *config)
{
	if (keycode == ESC)
		mlx_exit(config);
	else if (keycode == W)
		config->keys.w = 0;
	else if (keycode == A)
		config->keys.a = 0;
	else if (keycode == S)
		config->keys.s = 0;
	else if (keycode == D)
		config->keys.d = 0;
	else if (keycode == LARR)
		config->keys.larr = 0;
	else if (keycode == RARR)
		config->keys.rarr = 0;
	return (1);
}

int		press_key(int keycode, t_mlx_config *config)
{
	if (keycode == ESC)
		mlx_exit(config);
	else if (keycode == W)
		config->keys.w = 1;
	else if (keycode == A)
		config->keys.a = 1;
	else if (keycode == S)
		config->keys.s = 1;
	else if (keycode == D)
		config->keys.d = 1;
	else if (keycode == LARR)
		config->keys.larr = 1;
	else if (keycode == RARR)
		config->keys.rarr = 1;
	return (1);
}

void	set_event_listeners(t_mlx_config *config)
{
	mlx_hook(config->win_ptr, 3, 1L << 1, release_key, config);
	mlx_hook(config->win_ptr, 2, 1L << 0, press_key, config);
	mlx_hook(config->win_ptr, 17, 1L << 17, mlx_exit, config);
}
