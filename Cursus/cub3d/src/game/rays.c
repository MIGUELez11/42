/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:00:03 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/24 19:43:17 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


t_coords	detect_wall_hit(t_coords direction, t_mlx_config *cfg)
{
	t_player	player;
	t_coords	point;
	int			hitted;
	char		value;

	player = cfg->cub_cfg->player;
	point = player.position;
	hitted = 0;
	while (!hitted)
	{
		point.x += direction.x * GRID;
		point.y += direction.y * GRID;
		value = cub_map(cfg, (int)normalize_coord(point).x, (int)normalize_coord(point).y);
		hitted = value == '1' || value == '2';
		if (value == '\0')
			return ((t_coords){.x = 0, .y = 0});
	}
	return (point);

}

void		paint_wall(t_coords point, t_mlx_config *cfg)
{
	put_color_to_pixel(point, 0xFFFFFF, &cfg->img, cfg->mlx_ptr);
}

void		paint_walls(t_mlx_config *cfg)
{
	t_coords	point;
	double		i;
	int			check;
	t_coords	pos;
	t_coords	direction;

	check = cfg->cub_cfg->width > cfg->cub_cfg->height ? cfg->cub_cfg->width : cfg->cub_cfg->height;
	ft_printf("Map = %d %d\n", cfg->cub_cfg->map_width, cfg->cub_cfg->map_height);
	i = -check;
	while (i < check)
	{
		pos = (t_coords){
			.x = cfg->cub_cfg->player.camerapos.x + cfg->cub_cfg->player.cameradir.x * i,
			.y = cfg->cub_cfg->player.camerapos.y + cfg->cub_cfg->player.cameradir.y * i
		};
		direction = vector_2points(cfg->cub_cfg->player.position, pos);
		point = detect_wall_hit((vector_unit(direction)), cfg);
		if (!(normalize_coord(point).x <= 0 && normalize_coord(point).y <= 0))
		{
			cfg->cub_cfg->map[(int)normalize_coord(point).y][(int)normalize_coord(point).x] = '2';
			paint_wall(point, cfg);
		}
		i += 0.3;
	}
}
