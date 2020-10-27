/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:12:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/27 14:02:48 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		set_init_player_pos(t_mlx_config *cnf)
{
	t_player	*player;

	player = &cnf->cub_cfg->player;
	player->position = (t_coords){
		.x = (player->position.x + 0.5) * GRID,
		.y = (player->position.y + 0.5) * GRID
	};
	player->direction = (t_coords){
		.x = trunc(cos(player->heading) * 10000000000) / 10000000000,
		.y = trunc(sin(player->heading) * 10000000000) / 10000000000
	};
	player->camerapos = (t_coords){
		.x = player->position.x + player->direction.x * 10,
		.y = player->position.y + player->direction.y * 10
	};
	player->cameradir = vector_perp(player->direction);
}

void		player_move(t_mlx_config *cnf, int direction)
{
	t_player	*player;

	player = &cnf->cub_cfg->player;
	player->position.x += player->velocity.x * player->direction.x *
	DELTATIME * direction;
	player->position.y += player->velocity.y * player->direction.y *
	DELTATIME * direction;
	player->camerapos = (t_coords){
		.x = player->position.x + player->direction.x * 10,
		.y = player->position.y + player->direction.y * 10
	};
	player->cameradir = vector_perp(player->direction);
}

void		player_rotate(t_mlx_config *cnf, int direction)
{
	t_player	*player;
	double		speed;

	speed = 5 * (M_PI / 180);
	player = &cnf->cub_cfg->player;
	player->heading += speed * direction * DELTATIME;
	if (player->heading < 0)
		player->heading += 2 * M_PI;
	if (player->heading > 2 * M_PI)
		player->heading -= 2 * M_PI;
	player->direction.x = trunc(cos(player->heading) * 100000000) / 100000000;
	player->direction.y = trunc(sin(player->heading) * 100000000) / 100000000;
	player->cameradir = vector_perp(player->direction);
	player->camerapos = (t_coords){
		.x = player->position.x + player->direction.x * 10,
		.y = player->position.y + player->direction.y * 10
	};
}

void		player_controller(t_mlx_config *cnf)
{
	set_init_player_pos(cnf);
}
