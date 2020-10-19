/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:00:03 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/19 21:34:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_coords	detect_wall_hit(t_coords direction, t_mlx_config *cfg)
{
	t_coords	point;
	int			hitted;

	point = cfg->cub_cfg->player.position;

	hitted = 0;
	while (!hitted)
	{
		point.x = (normalize_coord(point).x + direction.x) * GRID;
		point.y = (normalize_coord(point).y + direction.y) * GRID;
		if (cub_map(cfg, normalize_coord(point).x, normalize_coord(point).y) == '1')
		{
			hitted = 1;
			ft_printf(" Hitted on %d %d\n", (int)point.x, (int)point.y);
		}
	}
	return (point);
}

void		paint_wall(t_coords point, t_mlx_config *cfg)
{
	double		x;
	double		y;
	t_coords	pixel;

	x = 0;
	while (x < 1)
	{
		pixel = cfg->cub_cfg->player.position;
		pixel.x += point.x + x;
		pixel.y += point.y;
		y = 0;
		while (y < 50)
		{
			pixel.y += 1;
			put_color_to_pixel(pixel, 0xFFFFFF, &cfg->img, cfg->mlx_ptr);
			y++;
		}
		x++;
	}
}

void		paint_walls(t_mlx_config *cfg)
{
	double	x;

	x = 0;
	while (x < cfg->cub_cfg->width)
	{
		paint_wall(detect_wall_hit(vector_2points(cfg->cub_cfg->player.position, (t_coords){.x = x, .y = cfg->cub_cfg->player.cameraPos.y}), cfg), cfg);
		x++;
	}
}
