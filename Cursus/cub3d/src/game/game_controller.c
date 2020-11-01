/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:47:36 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 16:08:31 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clear_mlx_config(t_mlx_config *config)
{
	ft_printf("win %p mlx %p\n", config->win_ptr, config->mlx_ptr);
	if (config->win_ptr)
	{
		mlx_clear_window(config->mlx_ptr, config->win_ptr);
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
		config->win_ptr = 0;
	}
	if (config->north.ptr)
		mlx_destroy_image(config->mlx_ptr, config->north.ptr);
	if (config->south.ptr)
		mlx_destroy_image(config->mlx_ptr, config->south.ptr);
	if (config->west.ptr)
		mlx_destroy_image(config->mlx_ptr, config->west.ptr);
	if (config->east.ptr)
		mlx_destroy_image(config->mlx_ptr, config->east.ptr);
	if (config->sprite.ptr)
		mlx_destroy_image(config->mlx_ptr, config->sprite.ptr);
	if (config->img.ptr)
		mlx_destroy_image(config->mlx_ptr, config->img.ptr);
	if (config->mlx_ptr)
		mlx_free_mlx_ptr(config->mlx_ptr);
	if (config->rays)
		free(config->rays);
}

int		update_loop(t_mlx_config *cfg)
{
	ft_printf("\e[1;31mw = %d \e[1;32ma = %d \e[1;33ms = %d \e[1;34md = %d\
	\e[0m\r", cfg->keys.w, cfg->keys.a, cfg->keys.s, cfg->keys.d);
	if (cfg->keys.w)
		player_move(cfg, 1);
	if (cfg->keys.s)
		player_move(cfg, -1);
	if (cfg->keys.a)
		player_rotate(cfg, -1);
	if (cfg->keys.d)
		player_rotate(cfg, 1);
	if (cfg->keys.w || cfg->keys.s || cfg->keys.a || cfg->keys.d)
	{
		if (cfg->img.ptr)
			mlx_destroy_image(cfg->mlx_ptr, cfg->img.ptr);
		draw_walls(cfg);
		mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img.ptr, 0, 0);
	}
	return (1);
}

void	initialize(t_cub_config *cub_config)
{
	t_mlx_config cfg;

	cfg.cub_cfg = cub_config;
	cfg.keys = (t_keys){.w = 0, .s = 0, .a = 0, .d = 0};
	generate_window(&cfg);
	player_controller(&cfg);
	printf("heading %f, oldP %f\n", cfg.player->heading,
	cfg.cub_cfg->player.heading);
	initialize_graphics(&cfg);
	set_event_listeners(&cfg);
	mlx_loop_hook(cfg.mlx_ptr, update_loop, &cfg);
	mlx_loop(cfg.mlx_ptr);
}
