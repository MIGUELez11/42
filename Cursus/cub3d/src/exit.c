/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:54:30 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/20 20:11:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_exit(char *msg, int code, t_cub_config *config)
{
	strerror(code);
	ft_printf("\e[1;31mError\n");
	ft_printf("%s (%s [%d])\n\e[0m", msg, strerror(code), code);
	if (config)
		clear_cub_config(config);

	ft_printf("\n\n\n");
	system("leaks cub3d");
	exit(code);
}