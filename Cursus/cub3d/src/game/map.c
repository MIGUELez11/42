/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:10:05 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/30 18:15:18 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		map_check(t_mlx_config *cfg, double dx, double dy)
{
	int	x;
	int	y;

	x = floor(dx / GRID);
	y = floor(dy / GRID);
	if (y >= 0 && y < cfg->cub_cfg->map_height &&
	x >= 0 && (size_t)x < ft_strlen(cfg->cub_cfg->map[y]))
	{
		if (cfg->cub_cfg->map[y][x] == '1')
			return (1);
		else if (cfg->cub_cfg->map[y][x] == '2')
			return (2);
	}
	return (0);
}
