/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:17:12 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/15 17:03:23 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	put_color_to_pixel(t_coords coords, int color, t_img *img, void *mlx_p)
{
	int pixel;

	if (img->bpp)
		color = mlx_get_color_value(mlx_p, color);
	pixel = (coords.y * img->line_size) + (coords.x * 4);
	if (img->endian == 1) // Most significant (Alpha) byte first
	{
		img->buff[pixel + 0] = (color >> 24);
		img->buff[pixel + 1] = (color >> 16) & 0xFF;
		img->buff[pixel + 2] = (color >> 8) & 0xFF;
		img->buff[pixel + 3] = (color)&0xFF;
	}
	else if (img->endian == 0) // Least significant (Blue) byte first
	{
		img->buff[pixel + 0] = (color) & 0xFF;
		img->buff[pixel + 1] = (color >> 8) & 0xFF;
		img->buff[pixel + 2] = (color >> 16) & 0xFF;
		img->buff[pixel + 3] = (color >> 24);
	}
}

void	initialize_graphics(t_mlx_config *cfg)
{
	ft_printf("%d %d", SCREEN_MAX_X, SCREEN_MAX_Y);
	cfg->img.ptr = mlx_new_image(cfg->mlx_ptr, cfg->cub_cfg->width, cfg->cub_cfg->height);
	cfg->img.w = cfg->cub_cfg->width;
	cfg->img.h = cfg->cub_cfg->height;
	cfg->img.buff = mlx_get_data_addr(cfg->img.ptr, &cfg->img.bpp, &cfg->img.line_size, &cfg->img.endian);
	int i = 0;
	while (i < cfg->cub_cfg->width)
	{
		int j = 0;
		while (j < cfg->cub_cfg->height)
		{
			put_color_to_pixel((t_coords){.x = i, .y = j}, 0xFF00FF + i*i + j*j, &cfg->img, cfg->mlx_ptr);
			j++;
		}
		i++;
	}
	ft_printf("\nbpp %d ls %d endian %d\n", cfg->img.bpp, cfg->img.line_size, cfg->img.endian);
	mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img.ptr, 0, 0);
}
