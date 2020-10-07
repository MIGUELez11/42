/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:41:07 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/07 11:49:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	generate_window(t_mlx_config *config)
{
	if (!(config->mlx_ptr = mlx_init()))
		cub_exit("Unable to start mlx", ENOMEM, config->cub_config);
	if (!(config->win_ptr = mlx_new_window(config->mlx_ptr,
	config->cub_config->resolution[0],
	config->cub_config->resolution[0], "cub3D")))
	{
		free(config->mlx_ptr);
		cub_exit("Unable to create mlx window", ENOMEM, config->cub_config);
	}
}
