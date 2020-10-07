/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:20:32 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/06 09:58:23 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

void	print_config(t_cub_config *config)
{
	int	i;

	ft_printf("NO %s\n", config->north);
	ft_printf("SO %s\n", config->south);
	ft_printf("WE %s\n", config->west);
	ft_printf("EA %s\n", config->east);
	ft_printf("S %s\n", config->sprite);
	ft_printf("R %d %d\n", config->resolution[0], config->resolution[1]);
	ft_printf("F %d,%d,%d\n", config->floor[0], config->floor[1],
	config->floor[2]);
	ft_printf("C %d,%d,%d\n", config->ceiling[0], config->ceiling[1],
	config->ceiling[2]);
	i = 0;
	while (config->map[i])
		ft_printf("%s\n", config->map[i++]);
	ft_printf("\n");
}
