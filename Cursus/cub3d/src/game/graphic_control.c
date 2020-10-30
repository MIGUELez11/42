/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:33:42 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/30 13:30:00 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void			put_color_to_pixel(t_coords coords,
t_img *img, t_mlx_config *cfg)
{
	int pixel;
	int	color;

	color = cfg->color;
	coords.x = floor(coords.x);
	coords.y = floor(coords.y);
	if (img->bpp != 32)
		color = mlx_get_color_value(cfg->mlx_ptr, color);
	pixel = ((int)coords.y * img->line_size) + ((int)coords.x * 4);
	if (img->endian == 1)
	{
		img->buff[pixel + 0] = (color >> 24);
		img->buff[pixel + 1] = (color >> 16) & 0xFF;
		img->buff[pixel + 2] = (color >> 8) & 0xFF;
		img->buff[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->buff[pixel + 0] = (color) & 0xFF;
		img->buff[pixel + 1] = (color >> 8) & 0xFF;
		img->buff[pixel + 2] = (color >> 16) & 0xFF;
		img->buff[pixel + 3] = (color >> 24);
	}
}

void			pick_wall_color(t_ray *ray, t_mlx_config *cfg)
{
	if (ray->was_hit_vert)
	{
		if (ray->wall_hit_x < cfg->player->position.x)
			cfg->color = 0x00ffff0;
		else
			cfg->color = 0x00ff001;
	}
	else
	{
		if (ray->wall_hit_y < cfg->player->position.y)
			cfg->color = 0xffff001;
		else
			cfg->color = 0xff00ff1;
	}
}

void			draw_walls(t_mlx_config *cfg)
{
	int		i;
	double	ray_angle;
	double	correct_distance;
	double	distance_projection_plane;
	double	wall_strip_height;

	cfg->img = create_image(cfg->cub_cfg->width, cfg->cub_cfg->height, cfg);
	ray_angle = cfg->player->heading - (FOV / 2);
	i = 0;
	while (i < cfg->cub_cfg->width)
	{
		cfg->rays[i] = new_ray(ray_angle);
		ray_cast(cfg->rays[i], cfg);
		correct_distance = cfg->rays[i]->distance * cos(cfg->rays[i]->ray_angle
		- cfg->player->heading);
		distance_projection_plane = cfg->cub_cfg->width / 2 / tan(FOV / 2);
		wall_strip_height = (GRID / correct_distance)
		* distance_projection_plane;
		pick_wall_color(cfg->rays[i], cfg);
		draw_rect((t_coords){.x = i * 1, .y = (cfg->cub_cfg->height / 2) -
		(wall_strip_height / 2)}, (t_coords){.x = 1, .y = wall_strip_height}
		, &cfg->img, cfg);
		i++;
		ray_angle += FOV / cfg->cub_cfg->width;
	}
}

t_img			create_image(int w, int h, t_mlx_config *cfg)
{
	t_img	img;

	img.ptr = mlx_new_image(cfg->mlx_ptr, w,
	h);
	img.w = w;
	img.h = h;
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp,
	&img.line_size, &img.endian);
	return (img);
}

void			initialize_graphics(t_mlx_config *cfg)
{
	cfg->img = create_image(cfg->cub_cfg->width, cfg->cub_cfg->height, cfg);
	cfg->rays = ft_calloc(cfg->cub_cfg->width, sizeof(t_ray *));
}
