/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:12:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/01 15:11:26 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	set_init_player_pos(t_mlx_config *cfg)
{
	t_player *player;

	player = &cfg->cub_cfg->player;
	player->position = (t_coords){
		.x = (player->position.x + 0.5) * GRID,
		.y = (player->position.y + 0.5) * GRID};
	cfg->player = player;
}

void	player_move(t_mlx_config *cfg, int direction)
{
	t_player *player;
	t_coords position;

	player = cfg->player;
	position = player->position;
	position.x += player->velocity.x * direction *
	cos(player->heading) * DELTATIME;
	position.y += player->velocity.y * direction *
	sin(player->heading) * DELTATIME;
	if (map_check(cfg, position.x, position.y) == 0)
		player->position = position;
}

void	player_rotate(t_mlx_config *cfg, int direction)
{
	t_player	*player;
	double		speed;

	speed = (GRID / 2) * (M_PI / 180);
	player = &cfg->cub_cfg->player;
	player->heading += speed * direction * DELTATIME;
	if (player->heading < 0)
		player->heading += 2 * M_PI;
	if (player->heading > 2 * M_PI)
		player->heading -= 2 * M_PI;
}

void	player_controller(t_mlx_config *cfg)
{
	set_init_player_pos(cfg);
}
