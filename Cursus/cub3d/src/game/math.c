/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:28:18 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/02 14:50:49 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double			rem(double a, double b)
{
	double	remain;

	remain = remainder(a, b);
	return (remain >= 0 ? remain : -remain);
}

/*
** AARRGGBB
*/

int				rgba_to_hex(int rgb[3])
{
	int	color;

	color = 0 & 0xFF;
	color <<= 8;
	color |= rgb[0] & 0xFF;
	color <<= 8;
	color |= rgb[1] & 0xFF;
	color <<= 8;
	color |= rgb[2] & 0xFF;
	return (color);
}

int				get_hex_from_pixel(char a, char r, char g, char b)
{
	int	color;

	color = OS == 0 ? 0xFF - (a & 0xFF) : a & 0xFF;
	color <<= 8;
	color |= r & 0xFF;
	color <<= 8;
	color |= g & 0xFF;
	color <<= 8;
	color |= b & 0xFF;
	return (color);
}
