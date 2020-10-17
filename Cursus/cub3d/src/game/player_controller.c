/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:12:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/17 23:41:42 by mflorido         ###   ########.fr       */
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
	printf("heading = %f\n", player->heading);
	player->direction = (t_coords){
		.x = cos(player->heading),
		.y = sin(player->heading)
	};
}
t_coords	normalize_coord(t_coords coord)
{
	return ((t_coords){	.x = floor(coord.x / GRID ),
						.y = floor(coord.y / GRID)});
}

void		player_move(t_mlx_config *cnf, int direction)
{
	t_player	*player;

	player = &cnf->cub_cfg->player;
	printf("\n\n\e[1;31mold position [%f, %f], velocity [%f, %f], direction [%f, %f], heading = %f\n", normalize_coord(player->position).x, normalize_coord(player->position).y, player->velocity.x, player->velocity.y, player->direction.x, player->direction.y, player->heading * (180 / M_PI));
	player->position.x += player->velocity.x * player->direction.x * DELTATIME * direction;
	player->position.y += player->velocity.y * player->direction.y * DELTATIME * direction;
	printf("\e[1;32mnew position [%f, %f], velocity [%f, %f], direction [%f, %f], heading = %f\e[0m\n\n", normalize_coord(player->position).x, normalize_coord(player->position).y, player->velocity.x, player->velocity.y, player->direction.x, player->direction.y, player->heading * (180 / M_PI));
}

void		player_rotate(t_mlx_config *cnf, int direction)
{
	t_player	*player;
	double		speed;

	speed = 5 * (M_PI / 180);
	player = &cnf->cub_cfg->player;
	printf("\n\n\e[1;31mold position [%f, %f], velocity [%f, %f], direction [%f, %f], heading = %f\n", normalize_coord(player->position).x, normalize_coord(player->position).y, player->velocity.x, player->velocity.y, player->direction.x, player->direction.y, player->heading * (180 / M_PI));
	player->heading	+= speed * direction * DELTATIME;
	if (player->heading < 0)
		player->heading += 2 * M_PI;
	if (player->heading > 2 * M_PI)
		player->heading -= 2 * M_PI;
	player->direction.x = cos(player->heading);
	player->direction.y = sin(player->heading);
	printf("\e[1;32mnew position [%f, %f], velocity [%f, %f], direction [%f, %f], heading = %f\e[0m\n\n", normalize_coord(player->position).x, normalize_coord(player->position).y, player->velocity.x, player->velocity.y, player->direction.x, player->direction.y, player->heading * (180 / M_PI));
}

void		player_controller(t_mlx_config *cnf)
{
	set_init_player_pos(cnf);
	printf("\n\nBefore GIRD = %d\nplayer pos (float) %f %f\n", GRID, cnf->cub_cfg->player.position.x, cnf->cub_cfg->player.position.y);
	printf("player pos (int) %f %f\n\n\n\n", normalize_coord(cnf->cub_cfg->player.position).x, normalize_coord(cnf->cub_cfg->player.position).y);
	printf("\n\nAfter GIRD = %d\nplayer pos (float) %f %f\n", GRID, cnf->cub_cfg->player.position.x, cnf->cub_cfg->player.position.y);
	printf("player pos (int) %f %f\n\n\n\n", normalize_coord(cnf->cub_cfg->player.position).x, normalize_coord(cnf->cub_cfg->player.position).y);
}