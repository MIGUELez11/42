/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:33:42 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 00:31:57 by mflorido         ###   ########.fr       */
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
		img->buff[pixel + 0] = (color >> 24) &0xFF;
		img->buff[pixel + 1] = (color >> 16) & 0xFF;
		img->buff[pixel + 2] = (color >> 8) & 0xFF;
		img->buff[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->buff[pixel + 0] = (color) & 0xFF;
		img->buff[pixel + 1] = (color >> 8) & 0xFF;
		img->buff[pixel + 2] = (color >> 16) & 0xFF;
		img->buff[pixel + 3] = (color >> 24) & 0xFF;
	}
}

/*
** AARRGGBB
*/

void			get_color_from_pixel(t_coords coords,
t_img *img, t_mlx_config *cfg)
{
	int pixel;
	int	color;

	coords.x = floor(coords.x);
	coords.y = floor(coords.y);
	pixel = ((int)coords.y * img->line_size) + ((int)coords.x * 4);
	if (img->endian == 1)
	{
		//AA
		color = img->buff[pixel + 0] & 0xFF;
		color <<= 8;
		//RR
		color |= img->buff[pixel + 1] & 0xFF;
		color <<= 8;
		// //GG
		color |= img->buff[pixel + 2] & 0xFF;
		color <<= 8;
		// //BB
		color |= img->buff[pixel + 3] & 0xFF;
	}
	else
	{
		//AA
		color = img->buff[pixel + 3] & 0xFF;
		color <<= 8;
		//RR
		color |= img->buff[pixel + 2] & 0xFF;
		color <<= 8;
		// //GG
		color |= img->buff[pixel + 1] & 0xFF;
		color <<= 8;
		// //BB
		color |= img->buff[pixel + 0] & 0xFF;
	}
	cfg->color = color;
}

void			draw_walls(t_mlx_config *cfg)
{
	int		i;
	double	ray_angle;
	double	distance_projection_plane;
	double	wall_strip_height;

	cfg->img = create_image(cfg->cub_cfg->width, cfg->cub_cfg->height, cfg);
	ray_angle = cfg->player->heading - (FOV / 2);
	i = 0;
	while (i < cfg->cub_cfg->width)
	{
		cfg->rays[i] = new_ray(ray_angle);
		cfg->ray = cfg->rays[i];
		ray_cast(cfg->rays[i], cfg);
		cfg->rays[i]->correct_distance = cfg->rays[i]->distance * cos(
		cfg->rays[i]->ray_angle - cfg->player->heading);
		distance_projection_plane = cfg->cub_cfg->width / 2 / tan(FOV / 2);
		wall_strip_height = (GRID / cfg->rays[i]->correct_distance)
		* distance_projection_plane;
		draw_rect((t_coords){.x = i * 1, .y = (cfg->cub_cfg->height / 2) -
		(wall_strip_height / 2)}, (t_coords){.x = 1, .y = wall_strip_height}
		, &cfg->img, cfg);
		i++;
		ray_angle += FOV / cfg->cub_cfg->width;
	}
}

void			initialize_graphics(t_mlx_config *cfg)
{
	cfg->north = create_image_from_file(cfg->cub_cfg->north, cfg);
	cfg->south = create_image_from_file(cfg->cub_cfg->south, cfg);
	cfg->east = create_image_from_file(cfg->cub_cfg->east, cfg);
	cfg->west = create_image_from_file(cfg->cub_cfg->west, cfg);
	cfg->sprite = create_image_from_file(cfg->cub_cfg->sprite, cfg);
	cfg->img = create_image(cfg->cub_cfg->width, cfg->cub_cfg->height, cfg);
	cfg->rays = ft_calloc(cfg->cub_cfg->width, sizeof(t_ray *));
}
