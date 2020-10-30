/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:20:32 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/28 12:43:38 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"
#include <stdio.h>

void	print_config(t_cub_config *config)
{
	int i;

	if (config->north)
		ft_printf("NO %p\n", config->north);
	if (config->south)
		ft_printf("SO %p\n", config->south);
	if (config->west)
		ft_printf("WE %p\n", config->south);
	if (config->east)
		ft_printf("EA %p\n", config->east);
	if (config->sprite)
		ft_printf("S %p\n", config->sprite);
	if (config->width && config->height)
		ft_printf("R %d %d\n", config->width, config->height);
	if (config->floor_set)
		ft_printf("F %d,%d,%d\n", config->floor[0], config->floor[1],
		config->floor[2]);
	if (config->ceiling_set)
		ft_printf("C %d,%d,%d\n", config->ceiling[0], config->ceiling[1],
		config->ceiling[2]);
	i = 0;
	ft_printf("\n");
	if (config->map && config->map[0])
		while (config->map[i])
			ft_printf("%s\n", config->map[i++]);
	ft_printf("\n");
	if (config->player.position.x)
		printf("Player position [%f, %f]\n",
		config->player.position.x, config->player.position.y);
	if (config->player.velocity.x)
		printf("Player velocity [%f, %f]\n",
		config->player.velocity.x, config->player.velocity.y);
}
