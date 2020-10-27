/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:47:36 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/27 23:17:46 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void clear_mlx_config(t_mlx_config *config)
{
	ft_printf("win %p mlx %p\n", config->win_ptr, config->mlx_ptr);
	if (config->win_ptr)
	{
		mlx_clear_window(config->mlx_ptr, config->win_ptr);
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
		config->win_ptr = 0;
	}
	if (config->img.ptr)
		mlx_destroy_image(config->mlx_ptr, config->img.ptr);
	if (config->mlx_ptr)
		mlx_free_mlx_ptr(config->mlx_ptr);
}

void clear_img(t_img *img)
{
	if (img->ptr)
		mlx_free_mlx_ptr(img->ptr);
}

int update_loop(t_mlx_config *cnf)
{
	ft_printf("\e[1;31mw = %d \e[1;32ma = %d \e[1;33ms = %d \e[1;34md = %d\
	\e[0m\r",
			  cnf->keys.w, cnf->keys.a, cnf->keys.s, cnf->keys.d);
	if (cnf->keys.w)
		player_move(cnf, 1);
	if (cnf->keys.s)
		player_move(cnf, -1);
	if (cnf->keys.a)
		player_rotate(cnf, 1);
	if (cnf->keys.d)
		player_rotate(cnf, -1);
	return (1);
}

char cub_map(t_mlx_config *cnf, int x, int y)
{
	if (y < cnf->cub_cfg->map_height &&
		(size_t)x < ft_strlen(cnf->cub_cfg->map[y]) &&
		y >= 0 && x >= 0)
		return (cnf->cub_cfg->map[y][x]);
	return ('\0');
}

double normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		return angle + (2 * M_PI);
	return angle;
}

void initialize(t_cub_config *cub_config)
{
	t_mlx_config config;

	config.cub_cfg = cub_config;
	config.keys = (t_keys){.w = 0, .s = 0, .a = 0, .d = 0};
	generate_window(&config);
	set_event_listeners(&config);
	player_controller(&config);
	initialize_graphics(&config);
	mlx_loop_hook(config.mlx_ptr, update_loop, &config);
	mlx_loop(config.mlx_ptr);
}
