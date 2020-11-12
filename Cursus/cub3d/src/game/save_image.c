/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:50:48 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/03 20:11:58 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void
	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int
	write_bmp_header(int fd, int filesize, t_mlx_config *cfg)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = cfg->img.w;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = cfg->img.h;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int
	get_color(t_mlx_config *cfg, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(cfg->img.buff
			+ (4 * (int)cfg->img.w * ((int)cfg->img.h - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int
	write_bmp_data(int file, t_mlx_config *cfg, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)cfg->img.h)
	{
		j = 0;
		while (j < (int)cfg->img.w)
		{
			color = get_color(cfg, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int
	save_bmp(t_mlx_config *cfg)
{
	int			filesize;
	int			file;
	int			pad;

	ft_printf("\e[1;33mSaving screenshot");
	pad = (4 - ((int)cfg->img.w * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)cfg->img.w + pad) * (int)cfg->img.h);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, cfg))
		return (0);
	if (!write_bmp_data(file, cfg, pad))
		return (0);
	close(file);
	ft_printf("\e\r[1;32mScreenshot saved ./screenshot.bmp\n\n\n\e[0m");
	return (1);
}
