/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:00:03 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 12:09:49 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/*
** /////////////////////////////////////////
** // Vertical Ray-Grid intersection code //
** /////////////////////////////////////////
*/

void	ray_cast_v(t_ray *ray, t_mlx_config *cfg)
{
	double	next_vert_touch_x;
	double	next_vert_touch_y;

	ray->xintercept = floor(cfg->player->position.x / GRID) * GRID;
	ray->xintercept += ray->is_ray_facing_right ? GRID : 0;
	ray->yintercept = cfg->player->position.y + (ray->xintercept -
	cfg->player->position.x) * tan(ray->ray_angle);
	ray->xstep = GRID;
	ray->xstep *= !ray->is_ray_facing_right ? -1 : 1;
	ray->ystep = GRID * tan(ray->ray_angle);
	ray->ystep *= (!ray->is_ray_facing_down && ray->ystep > 0) ? -1 : 1;
	ray->ystep *= (ray->is_ray_facing_down && ray->ystep < 0) ? -1 : 1;
	next_vert_touch_x = ray->xintercept;
	next_vert_touch_y = ray->yintercept;
	ray_cast_loopv(ray, next_vert_touch_x, next_vert_touch_y, cfg);
}

/*
** ///////////////////////////////////////////
** // Horizontal Ray-Grid intersection code //
** ///////////////////////////////////////////
*/

void	ray_cast_h(t_ray *ray, t_mlx_config *cfg)
{
	double	next_horz_touch_x;
	double	next_horz_touch_y;

	ray->yintercept = floor(cfg->player->position.y / GRID) * GRID;
	ray->yintercept += ray->is_ray_facing_down ? GRID : 0;
	ray->xintercept = cfg->player->position.x + (ray->yintercept -
	cfg->player->position.y) / tan(ray->ray_angle);
	ray->ystep = GRID;
	ray->ystep *= !ray->is_ray_facing_down ? -1 : 1;
	ray->xstep = GRID / tan(ray->ray_angle);
	ray->xstep *= (!ray->is_ray_facing_right && ray->xstep > 0) ? -1 : 1;
	ray->xstep *= (ray->is_ray_facing_right && ray->xstep < 0) ? -1 : 1;
	next_horz_touch_x = ray->xintercept;
	next_horz_touch_y = ray->yintercept;
	ray_cast_looph(ray, next_horz_touch_x, next_horz_touch_y, cfg);
}

void	ray_cast_near(t_ray *ray, t_mlx_config *cfg)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = ray->found_horz_hit ? vector_distance(
	cfg->player->position, (t_coords){.x = ray->hwall_hit_x, .y =
	ray->hwall_hit_y}) : 2147483647.0;
	vert_hit_distance = ray->found_vert_hit ? vector_distance(
	cfg->player->position, (t_coords){.x = ray->vwall_hit_x, .y =
	ray->vwall_hit_y}) : 2147483647.0;
	ray->wall_hit_x = horz_hit_distance < vert_hit_distance ? ray->hwall_hit_x
	: ray->vwall_hit_x;
	ray->wall_hit_y = horz_hit_distance < vert_hit_distance ? ray->hwall_hit_y
	: ray->vwall_hit_y;
	ray->distance = horz_hit_distance < vert_hit_distance ? horz_hit_distance
	: vert_hit_distance;
	ray->was_hit_vert = vert_hit_distance < horz_hit_distance;
}

void	ray_cast(t_ray *ray, t_mlx_config *cfg)
{
	ray_cast_h(ray, cfg);
	ray_cast_v(ray, cfg);
	ray_cast_near(ray, cfg);
	ray->hit_type = map_check(cfg, ray->wall_hit_x - (!ray->is_ray_facing_right && ray->was_hit_vert
	? 1 : 0), ray->wall_hit_y - (!ray->is_ray_facing_down && !ray->was_hit_vert ? 1 : 0));
}

t_ray	*new_ray(double ray_angle)
{
	static t_ray	ray;

	ray.ray_angle = normalize_angle(ray_angle);
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
	return (&ray);
}
