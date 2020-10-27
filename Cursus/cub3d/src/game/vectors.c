/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez11 <miguelez11@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:59:27 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/27 21:58:39 by miguelez11       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

double vector_distance(t_coords a, t_coords b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

t_coords vector_unit(t_coords v)
{
	double module;

	module = vector_distance((t_coords){.x = 0, .y = 0}, v);
	if (v.x == 0 && v.y == 0)
		return (v);
	return ((t_coords){.x = v.x / module, .y = v.y / module});
}

double vector_angle(t_coords r, t_coords s)
{
	double distance_product;
	t_coords v;

	v = (t_coords){.x = 0, .y = 0};
	distance_product = vector_distance(r, v) * vector_distance(s, v);
	return (acos((r.x * s.x + r.y * s.y) / distance_product));
}

double rad_deg(double angle, char *unit)
{
	if (unit[0] == 'r')
		return (angle * 180 / M_PI);
	else
		return (angle * M_PI / 180);
}

t_coords normalize_coord(t_coords coord)
{
	return ((t_coords){.x = floor(coord.x / GRID),
					   .y = floor(coord.y / GRID)});
}

t_coords vector_2points(t_coords p, t_coords q)
{
	return ((t_coords){.x = q.x - p.x, .y = q.y - p.y});
}

t_coords vector_perp(t_coords v)
{
	return ((t_coords){.x = v.y, .y = -v.x});
}