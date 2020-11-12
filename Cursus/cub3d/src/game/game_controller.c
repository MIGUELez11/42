/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:47:36 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/11 17:01:10 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clear_mlx_config(t_mlx_config *config)
{
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
	if (cfg->keys.w)
		player_move(cfg, 1);
	if (cfg->keys.s)
		player_move(cfg, -1);
	if (cfg->keys.a)
		player_strafe(cfg, 1);
	if (cfg->keys.d)
		player_strafe(cfg, -1);
	if (cfg->keys.larr)
		player_rotate(cfg, -1);
	if (cfg->keys.rarr)
		player_rotate(cfg, 1);
	if (cfg->keys.w || cfg->keys.s || cfg->keys.a || cfg->keys.d
	|| cfg->keys.larr || cfg->keys.rarr)
	{
		if (cfg->img.ptr)
			mlx_destroy_image(cfg->mlx_ptr, cfg->img.ptr);
		draw_walls(cfg);
		draw_objects(cfg);
		mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img.ptr, 0, 0);
	}
	return (1);
}

void	initialize(t_cub_config *cub_config)
{
	t_mlx_config cfg;

	cfg.cub_cfg = cub_config;
	cfg.keys = (t_keys){.w = 0, .s = 0, .a = 0, .d = 0, .larr = 0, .rarr = 0};
	generate_window(&cfg);
	player_controller(&cfg);
	initialize_graphics(&cfg);
	set_event_listeners(&cfg);
	mlx_loop_hook(cfg.mlx_ptr, update_loop, &cfg);
	mlx_loop(cfg.mlx_ptr);
}
