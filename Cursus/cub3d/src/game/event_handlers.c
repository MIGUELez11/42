/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:41:10 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/30 11:29:54 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		mlx_exit(void *config)
{
	ft_printf("Hola");
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
	if (keycode == 53)
		mlx_exit(config);
	else if (keycode == 13)
		config->keys.w = 0;
	else if (keycode == 0)
		config->keys.a = 0;
	else if (keycode == 1)
		config->keys.s = 0;
	else if (keycode == 2)
		config->keys.d = 0;
	else
		ft_printf("key %d released\n", keycode);
	return (1);
}

int		press_key(int keycode, t_mlx_config *config)
{
	if (keycode == 53)
		mlx_exit(config);
	else if (keycode == 13)
		config->keys.w = 1;
	else if (keycode == 0)
		config->keys.a = 1;
	else if (keycode == 1)
		config->keys.s = 1;
	else if (keycode == 2)
		config->keys.d = 1;
	else
		ft_printf("key %d pressed\n", keycode);
	return (1);
}

void	set_event_listeners(t_mlx_config *config)
{
	mlx_hook(config->win_ptr, 3, 1L << 1, release_key, config);
	mlx_hook(config->win_ptr, 2, 1L << 1, press_key, config);
	mlx_hook(config->win_ptr, 17, 1L << 17, mlx_exit, config);
}
