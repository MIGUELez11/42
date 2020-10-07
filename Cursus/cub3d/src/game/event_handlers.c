/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:41:10 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/07 11:55:23 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		mlx_exit(void *config)
{
	ft_printf("Hola");
	if (config)
	{
		clear_mlx_config(config);
		cub_exit("", 0, ((t_mlx_config *)config)->cub_config);
	}
	cub_exit("", 0, NULL);
	return (1);
}

int		print_key(int keycode, t_mlx_config *config)
{
	if (keycode == 53)
		mlx_exit(config);
	else if (keycode == 13)
		ft_printf("Presionada w\n");
	else if (keycode == 0)
		ft_printf("Presionada a\n");
	else if (keycode == 1)
		ft_printf("Presionada s\n");
	else if (keycode == 2)
		ft_printf("Presionada d\n");
	else
		ft_printf("tecla %d presionada\n", keycode);
	return (1);
}

void	set_event_listeners(t_mlx_config *config)
{
	mlx_hook(config->win_ptr, 3, 1L << 1, print_key, config);
	mlx_hook(config->win_ptr, 17, 0, mlx_exit, config);
}
