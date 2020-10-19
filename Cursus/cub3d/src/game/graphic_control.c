/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:33:42 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/19 22:00:07 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

unsigned long	rgba_to_hex(int rgb[3])
{
	int r;
	int g;
	int b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

/*
** endian 0 = Least significant (Blue) byte first
** endian 1 = Most significant (Alpha) byte first
*/

void			put_color_to_pixel(t_coords coords, int color,
t_img *img, void *mlx_p)
{
	int pixel;

	if (img->bpp)
		color = mlx_get_color_value(mlx_p, color);
	pixel = (coords.y * img->line_size) + (coords.x * 4);
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

void			initialize_graphics(t_mlx_config *cfg)
{
	int i;
	int j;

	ft_printf("%d %d", SCREEN_MAX_X, SCREEN_MAX_Y);
	cfg->img.ptr = mlx_new_image(cfg->mlx_ptr, cfg->cub_cfg->width,
	cfg->cub_cfg->height);
	cfg->img.w = cfg->cub_cfg->width;
	cfg->img.h = cfg->cub_cfg->height;
	cfg->img.buff = mlx_get_data_addr(cfg->img.ptr, &cfg->img.bpp,
	&cfg->img.line_size, &cfg->img.endian);
	i = 0;
	while (i < cfg->cub_cfg->width)
	{
		j = 0;
		while (j < cfg->cub_cfg->height)
		{
			put_color_to_pixel((t_coords){.x = i, .y = j}, rgba_to_hex(j < cfg->cub_cfg->height / 4 ? cfg->cub_cfg->ceiling : cfg->cub_cfg->floor) + i*i + j*j, &cfg->img, cfg->mlx_ptr);
			j++;
		}
		i++;
	}
	ft_printf("\nbpp %d ls %d endian %d\n", cfg->img.bpp, cfg->img.line_size,
	cfg->img.endian);
	// paint_walls(cfg);
	mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img.ptr, 0, 0);
}
