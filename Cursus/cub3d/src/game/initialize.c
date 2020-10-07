/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:47:36 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/07 11:42:15 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clear_mlx_config(t_mlx_config *config)
{
	ft_printf("win %p mlx %p\n", config->win_ptr, config->mlx_ptr);
	if (config->win_ptr)
	{
		mlx_clear_window(config->mlx_ptr, config->win_ptr);
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
		config->win_ptr = 0;
	}
	if (config->mlx_ptr)
		mlx_free_mlx_ptr(config->mlx_ptr);
}

void	initialize(t_cub_config *cub_config)
{
	t_mlx_config	config;

	config.cub_config = cub_config;
	generate_window(&config);
	set_event_listeners(&config);
	mlx_loop(config.mlx_ptr);
}
