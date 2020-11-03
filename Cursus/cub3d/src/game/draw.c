/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:46:00 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/03 20:09:04 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_wall(t_coords a, t_coords b, t_img *img, t_mlx_config *cfg)
{
	int	i;
	int	j;

	i = 0;
	while (i <= b.x)
	{
		j = 0;
		while (j <= b.y)
		{
			if (a.x + i < img->w && a.x + i >= 0 && a.y + j < img->h && a.y +
			j >= 0)
			{
				pick_color(cfg->ray, (t_coords){.x = i, .y = j},
				(t_coords){.x = b.x, .y = b.y}, cfg);
				put_color_to_pixel((t_coords){.x = a.x + i, .y = a.y + j}, img,
				cfg);
			}
			j++;
		}
		i++;
	}
}

void	draw_line(t_coords a, t_coords b, t_img *img, t_mlx_config *cfg)
{
	double		i;
	double		j;
	t_coords	vector;

	vector = vector_2points(a, b);
	i = 0;
	j = 0;
	while ((a.x < b.x ? a.x + i <= b.x : a.x + i >= b.x) && (a.y < b.y ? a.y +
	j <= b.y : a.y + j >= b.y))
	{
		if (a.x + i < img->w && a.x + i >= 0 && a.y + j < img->h && a.y + j
		>= 0)
		{
			put_color_to_pixel((t_coords){.x = a.x + i, .y = a.y + j}, img,
			cfg);
		}
		i += vector.x / (vector.x > vector.y ? vector.x : vector.y);
		j += vector.y / (vector.x > vector.y ? vector.x : vector.y);
	}
}
