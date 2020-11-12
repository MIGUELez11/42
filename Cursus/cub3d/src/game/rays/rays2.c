/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:39:59 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/02 14:52:53 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ray_cast_loopv(t_ray *ray, double next_vert_touch_x,
double next_vert_touch_y, t_mlx_config *cfg)
{
	while (next_vert_touch_x >= 0 && next_vert_touch_x <=
	cfg->cub_cfg->map_width * GRID && next_vert_touch_y >= 0 &&
	next_vert_touch_y <= cfg->cub_cfg->map_height * GRID)
	{
		ray->v_hit_type = map_check(cfg, next_vert_touch_x -
		(!ray->is_ray_facing_right ? 1 : 0), next_vert_touch_y);
		if (ray->v_hit_type <= ray->wall_type && ray->v_hit_type > 0)
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
double next_horz_touch_y, t_mlx_config *cfg)
{
	while (next_horz_touch_x >= 0 && next_horz_touch_x <=
	cfg->cub_cfg->map_width * GRID && next_horz_touch_y >= 0 &&
	next_horz_touch_y <= cfg->cub_cfg->map_height * GRID)
	{
		ray->h_hit_type = map_check(cfg, next_horz_touch_x, next_horz_touch_y -
		(!ray->is_ray_facing_down ? 1 : 0));
		if (ray->h_hit_type <= ray->wall_type && ray->h_hit_type > 0)
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
