/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:12:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/02 15:31:08 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img			create_image(int w, int h, t_mlx_config *cfg)
{
	t_img	img;
	int		x;
	int		y;

	img.ptr = mlx_new_image(cfg->mlx_ptr, w,
	h);
	img.w = w;
	img.h = h;
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp,
	&img.line_size, &img.endian);
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h / 2)
		{
			cfg->color = rgba_to_hex(cfg->cub_cfg->ceiling);
			put_color_to_pixel((t_coords){.x = x, .y = y}, &img, cfg);
			cfg->color = rgba_to_hex(cfg->cub_cfg->floor);
			put_color_to_pixel((t_coords){.x = x, .y = y + h / 2}, &img, cfg);
			y++;
		}
		x++;
	}
	return (img);
}

t_img			create_image_from_file(char *filename, t_mlx_config *cfg)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(cfg->mlx_ptr, filename, &img.w, &img.h);
	if (!img.ptr)
		return (img);
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp,
	&img.line_size, &img.endian);
	return (img);
}

/*
** In order: WENS
*/

void			pick_object_color(t_ray *ray, t_coords coords, t_coords coords2
				, t_mlx_config *cfg)
{
	if (ray->was_hit_vert)
		get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_y, GRID)
		+ coords.x) * cfg->sprite.w / GRID, .y = coords.y / coords2.y *
		cfg->sprite.h}, &cfg->sprite, cfg);
	else
		get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_x, GRID)
		+ coords.x) * cfg->sprite.w / GRID, .y = coords.y / coords2.y *
		cfg->sprite.h}, &cfg->sprite, cfg);
}

void			pick_wall_color(t_ray *ray, t_coords coords, t_coords coords2,
				t_mlx_config *cfg)
{
	if (ray->was_hit_vert)
	{
		if (ray->wall_hit_x < cfg->player->position.x)
			get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_y, GRID)
			+ coords.x) * cfg->west.w / GRID, .y = coords.y / coords2.y *
			cfg->west.h}, &cfg->west, cfg);
		else
			get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_y, GRID)
			+ coords.x) * cfg->east.w / GRID, .y = coords.y / coords2.y *
			cfg->east.h}, &cfg->east, cfg);
	}
	else
	{
		if (ray->wall_hit_y < cfg->player->position.y)
			get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_x, GRID)
			+ coords.x) * cfg->north.w / GRID, .y = coords.y / coords2.y *
			cfg->north.h}, &cfg->north, cfg);
		else
			get_color_from_pixel((t_coords){.x = (rem(ray->wall_hit_x, GRID)
			+ coords.x) * cfg->south.w / GRID, .y = coords.y / coords2.y *
			cfg->south.h}, &cfg->south, cfg);
	}
}

void			pick_color(t_ray *ray, t_coords coords, t_coords coords2,
				t_mlx_config *cfg)
{
	if (ray->hit_type == 1)
		pick_wall_color(ray, coords, coords2, cfg);
	else if (ray->hit_type == 2)
		pick_object_color(ray, coords, coords2, cfg);
}
