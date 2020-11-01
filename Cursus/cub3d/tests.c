#include "minilibx_linux/mlx.h"
#include "src/cub3d.h"
#include "src/game/game.h"
#include "src/map_settings/map_settings.h"
#include "libft/libft.h"
#include <stdio.h>

void			put_color_to_pixel(t_coords coords,
t_img *img, t_mlx_config *cfg)
{
	int 			pixel;
	unsigned int	color;

	color = cfg->color;
	coords.x = floor(coords.x);
	coords.y = floor(coords.y);
	if (img->bpp != 32)
		color = mlx_get_color_value(cfg->mlx_ptr, color);
	pixel = ((int)coords.y * img->line_size) + ((int)coords.x * 4);
	ft_printf("%d", 0xFF000000 > cfg->color);
	if (color < 0xFF000000)
	{
		ft_printf("Dentro");
		if (img->endian == 1)
		{
			img->buff[pixel + 0] = (color >> 24) & 0xFF;
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

int	main()
{
	t_mlx_config	cfg;
	t_img			img;

	cfg.mlx_ptr = mlx_init();
	cfg.win_ptr = mlx_new_window(cfg.mlx_ptr, 500, 500, "Hola");
	cfg.img.ptr = mlx_new_image(cfg.mlx_ptr, 500, 500);
	cfg.img.w = 500;
	cfg.img.h = 500;
	cfg.img.buff = mlx_get_data_addr(cfg.img.ptr, &cfg.img.bpp, &cfg.img.line_size, &cfg.img.endian);
	img.ptr = mlx_xpm_file_to_image(cfg.mlx_ptr, "assets/banner.xpm", &img.w, &img.h);
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_size, &img.endian);
	for (int x = 0; x < img.w; x++)
		for (int y = 0; y < img.h; y++)
		{
			// get_color_from_pixel((t_coords){.x = x, .y = y}, &img, &cfg);
			cfg.color = 0xffff0000;
			put_color_to_pixel((t_coords){.x = x, .y = y}, &cfg.img, &cfg);
			cfg.color = 0x00ff0000;
			put_color_to_pixel((t_coords){.x = img.w + x, .y = y}, &cfg.img, &cfg);
		}
	mlx_put_image_to_window(cfg.mlx_ptr, cfg.win_ptr, cfg.img.ptr, 0, 0);
	mlx_loop(cfg.mlx_ptr);
}