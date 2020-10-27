/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:00:03 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/27 17:13:16 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ray_cast_v(t_ray *ray, t_mlx_config *cfg)
{
	/////////////////////////////////////////
	// Vertical Ray-Grid intersection code //
	/////////////////////////////////////////
	double	next_vert_touch_x;
	double	next_vert_touch_y;
	//find the x-coodinate of the closest vertical grid intersection
	ray->xintercept = floor(cfg->cub_cfg->player.position.x / GRID) * GRID;
	ray->xintercept += ray->is_ray_facing_right ? GRID : 0;
	//Find the y-coordinate of the closest vertical grid intersection
	ray->yintercept = cfg->cub_cfg->player.position.y + (ray->xintercept - cfg->cub_cfg->player.position.x) * tan(ray->ray_angle);
	//Calculate the increment for xStep and yStep
	ray->xstep = GRID;
	ray->xstep *= !ray->is_ray_facing_right ? -1 : 1;
	ray->ystep = GRID * tan(ray->ray_angle);
	ray->ystep *= (!ray->is_ray_facing_down && ray->ystep > 0) ? -1 : 1;
	ray->ystep *= (ray->is_ray_facing_down && ray->ystep < 0) ? -1 : 1;
	next_vert_touch_x = ray->xintercept;
	next_vert_touch_y = ray->yintercept;
	if (!ray->is_ray_facing_right)
		next_vert_touch_x--;
	//Increment xStep and yStep until we find a wall
		printf("Ray = [%f, %f] [%f]\n", next_vert_touch_x, next_vert_touch_y, ray->ray_angle);
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= cfg->cub_cfg->width && next_vert_touch_y >= 0 && next_vert_touch_y <= cfg->cub_cfg->height)
	{
		if (cub_map(cfg, next_vert_touch_x, next_vert_touch_y) == '1')
		{
			ray->found_vert_hit = 1;
			if (!ray->is_ray_facing_right)
				next_vert_touch_x++;
			ray->vwall_hit_x = next_vert_touch_x;
			ray->vwall_hit_y = next_vert_touch_y;
			break;
		}
		else
		{
			next_vert_touch_x += ray->xstep;
			next_vert_touch_y += ray->ystep;
		}
	}
}
void	ray_cast_h(t_ray *ray, t_mlx_config *cfg)
{
	double	next_horz_touch_x;
	double	next_horz_touch_y;
	///////////////////////////////////////////
	// Horizontal Ray-Grid intersection code //
	///////////////////////////////////////////
	//Find the y-coordinate of the closes horizontal grid intersection
	ray->yintercept = floor(cfg->cub_cfg->player.position.y / GRID) * GRID;
	ray->yintercept += ray->is_ray_facing_down ? GRID : 0;
	//Find the x-coordinate of the closes horizontal grid intersection
	ray->xintercept = cfg->cub_cfg->player.position.x + (ray->yintercept - cfg->cub_cfg->player.position.y) / tan(ray->ray_angle);
	//Calculate the increment for xStep and yStep
	ray->ystep = GRID;
	ray->ystep *= !ray->is_ray_facing_down ? -1 : 1;
	ray->xstep = GRID / tan(ray->ray_angle);
	ray->xstep *= (!ray->is_ray_facing_right && ray->xstep > 0) ? -1 : 1;
	ray->xstep *= (ray->is_ray_facing_right && ray->xstep < 0) ? -1 : 1;
	next_horz_touch_x = ray->xintercept;
	next_horz_touch_y = ray->yintercept;
	if (!ray->is_ray_facing_down)
		next_horz_touch_y--;
	//Increment xStep and yStep until we find a wall
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= cfg->cub_cfg->width && next_horz_touch_y >= 0 && next_horz_touch_y <= cfg->cub_cfg->height)
	{
		if (cub_map(cfg, next_horz_touch_x, next_horz_touch_y) == '1')
		{
			ray->found_horz_hit = 1;
			if (!ray->is_ray_facing_down)
				next_horz_touch_y++;
			ray->hwall_hit_x = next_horz_touch_x;
			ray->hwall_hit_y = next_horz_touch_y;
			break;
		}
		else
		{
			next_horz_touch_x += ray->xstep;
			next_horz_touch_y += ray->ystep;
		}
	}
}

void	ray_cast_near(t_ray *ray, t_mlx_config *cfg)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	//Calculate both distances and choose the smaller
	horz_hit_distance = ray->found_horz_hit ? vector_distance(cfg->cub_cfg->player.position, (t_coords){.x = ray->hwall_hit_x, .y = ray->hwall_hit_y}) : 2147483647.0;
	vert_hit_distance = ray->found_vert_hit ? vector_distance(cfg->cub_cfg->player.position, (t_coords){.x = ray->vwall_hit_x, .y = ray->vwall_hit_y}) : 2147483647.0;
	ray->wall_hit_x = horz_hit_distance < vert_hit_distance ? ray->hwall_hit_x : ray->vwall_hit_x;
	ray->wall_hit_y = horz_hit_distance < vert_hit_distance ? ray->hwall_hit_y : ray->vwall_hit_y;
	ray->distance = horz_hit_distance < vert_hit_distance ? horz_hit_distance : vert_hit_distance;
	ray->was_hit_vert = vert_hit_distance < horz_hit_distance;
}

void	ray_cast(t_ray *ray, t_mlx_config *cfg)
{
	ray_cast_h(ray, cfg);
	ray_cast_v(ray, cfg);
	ray_cast_near(ray, cfg);
}

t_ray	new_ray(double ray_angle)
{
	t_ray	ray;

	ray.ray_angle = normalize_angle(ray_angle);
	printf("Angle '%f' '%f'\n", ray.ray_angle, tan(ray.ray_angle));
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.was_hit_vert = 0;
	ray.is_ray_facing_down = ray.ray_angle > 0 && ray.ray_angle < M_PI;
	ray.is_ray_facing_right = ray.ray_angle < 0.5 * M_PI ||
	ray.ray_angle > 1.5 * M_PI;
	ray.hwall_hit_x = 0;
	ray.hwall_hit_y = 0;
	ray.vwall_hit_x = 0;
	ray.vwall_hit_y = 0;
	ray.found_horz_hit = 0;
	ray.found_vert_hit = 0;
	return ray;
}
