/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:59:27 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/30 18:26:27 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double		vector_angle(t_coords r, t_coords s)
{
	double		distance_product;
	t_coords	v;

	v = (t_coords){.x = 0, .y = 0};
	distance_product = vector_distance(r, v) * vector_distance(s, v);
	return (acos((r.x * s.x + r.y * s.y) / distance_product));
}

double		rad_deg(double angle, char *unit)
{
	if (unit[0] == 'r')
		return (angle * 180 / M_PI);
	else
		return (angle * M_PI / 180);
}

double		normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		return (angle + (2 * M_PI));
	return (angle);
}
