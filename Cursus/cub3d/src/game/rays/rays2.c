/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:39:59 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 17:08:59 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ray_cast_loopv(t_ray *ray, double next_vert_touch_x,
double next_vert_touch_y, t_mlx_config *cfg, int wall_type)
{
	ft_printf("walltype = %d\n", wall_type);
	while (next_vert_touch_x >= 0 && next_vert_touch_x <=
	cfg->cub_cfg->map_width * GRID && next_vert_touch_y >= 0 &&
	next_vert_touch_y <= cfg->cub_cfg->map_height * GRID)
	{
		if (map_check(cfg, next_vert_touch_x - (!ray->is_ray_facing_right ? 1 :
		0), next_vert_touch_y) == wall_type)
		{
			ray->found_vert_hit = 1;
			ray->vwall_hit_x = next_vert_touch_x;
			ray->vwall_hit_y = next_vert_touch_y;
			break ;
		}
		else
		{
			next_vert_touch_x += ray->xstep;
			next_vert_touch_y += ray->ystep;
		}
	}
}

void	ray_cast_looph(t_ray *ray, double next_horz_touch_x,
double next_horz_touch_y, t_mlx_config *cfg, int wall_type)
{
	while (next_horz_touch_x >= 0 && next_horz_touch_x <=
	cfg->cub_cfg->map_width * GRID && next_horz_touch_y >= 0 &&
	next_horz_touch_y <= cfg->cub_cfg->map_height * GRID)
	{
		if (map_check(cfg, next_horz_touch_x, next_horz_touch_y -
		(!ray->is_ray_facing_down ? 1 : 0)) == wall_type)
		{
			ray->found_horz_hit = 1;
			ray->hwall_hit_x = next_horz_touch_x;
			ray->hwall_hit_y = next_horz_touch_y;
			break ;
		}
		else
		{
			next_horz_touch_x += ray->xstep;
			next_horz_touch_y += ray->ystep;
		}
	}
}
