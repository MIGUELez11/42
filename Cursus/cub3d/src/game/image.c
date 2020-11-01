/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:12:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 10:27:27 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img			create_image(int w, int h, t_mlx_config *cfg)
{
	t_img	img;

	img.ptr = mlx_new_image(cfg->mlx_ptr, w,
	h);
	img.w = w;
	img.h = h;
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp,
	&img.line_size, &img.endian);
	cfg->color = rgba_to_hex(cfg->cub_cfg->ceiling);
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h / 2; y++)
			put_color_to_pixel((t_coords){.x = x, .y = y}, &img, cfg);
	cfg->color = rgba_to_hex(cfg->cub_cfg->floor);
	for (int x = 0; x < w; x++)
	for (int y = h / 2; y < h; y++)
		put_color_to_pixel((t_coords){.x = x, .y = y}, &img, cfg);
	return (img);
}


t_img			create_image_from_file(char *filename, t_mlx_config *cfg)
{
	t_img	img;

	if (check_extension(filename, "xpm"))
		img.ptr = mlx_xpm_file_to_image(cfg->mlx_ptr, filename, &img.w, &img.h);
	else if (check_extension(filename, "png"))
		img.ptr = mlx_png_file_to_image(cfg->mlx_ptr, filename, &img.w, &img.h);
	if (!img.ptr)
		return img;
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp,
	&img.line_size, &img.endian);
	return (img);
}

void			pick_wall_color(t_ray *ray, t_coords coords, t_coords coords2, t_mlx_config *cfg)
{
	if (ray->hit_type == 2)
	{
		if (ray->was_hit_vert)
			get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_y, GRID) + coords.x) * cfg->sprite.w / GRID, .y = coords.y / coords2.y * cfg->sprite.h}, &cfg->sprite, cfg);
		else
			get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_x, GRID) + coords.x) * cfg->sprite.w / GRID, .y = coords.y / coords2.y * cfg->sprite.h}, &cfg->sprite, cfg);
		if (cfg->color == (int)0xff000000)
			cfg->color = 0x000000;
	}

	else
		if (ray->was_hit_vert)
		{
			if (ray->wall_hit_x < cfg->player->position.x)
				//O
				get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_y, GRID) + coords.x) * cfg->west.w / GRID, .y = coords.y / coords2.y * cfg->west.h}, &cfg->west, cfg);
			else //E
				get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_y, GRID) + coords.x) * cfg->east.w / GRID, .y = coords.y / coords2.y * cfg->east.h}, &cfg->east, cfg);
		}
		else
		{
			if (ray->wall_hit_y < cfg->player->position.y)
				//N
				get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_x, GRID) + coords.x) * cfg->north.w / GRID, .y = coords.y / coords2.y * cfg->north.h}, &cfg->north, cfg);
			else
				//S
				get_color_from_pixel((t_coords){.x = (remainder(ray->wall_hit_x, GRID) + coords.x) * cfg->south.w / GRID, .y = coords.y / coords2.y * cfg->south.h}, &cfg->south, cfg);
		}
}

int				rgba_to_hex(int rgb[3])
{
	int	color;

	//AA
	color = 0 & 0xFF;
	color <<= 8;
	//RR
	color |= rgb[0] & 0xFF;
	color <<= 8;
	// //GG
	color |= rgb[1] & 0xFF;
	color <<= 8;
	// //BB
	color |= rgb[2] & 0xFF;
	return (color);
}