/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:54:30 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/11 17:00:11 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

void	cub_exit(char *msg, int code, t_cub_config *config)
{
	if (config)
	{
		clear_cub_config(config);
	}
	if (code != 0)
		ft_printf("\e[1;31mError\n%s (%s [%d])\n\e[0m",
		msg, strerror(code), code);
	else
		ft_printf("\e[1;32mExit successfully\n%s (%s [%d])\e[0m\n",
		msg, "Exit success", code);
	exit(code);
}
