/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:59:27 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/30 18:26:12 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double		vector_distance(t_coords a, t_coords b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

t_coords	vector_unit(t_coords v)
{
	double module;

	module = vector_distance((t_coords){.x = 0, .y = 0}, v);
	if (v.x == 0 && v.y == 0)
		return (v);
	return ((t_coords){.x = v.x / module, .y = v.y / module});
}

t_coords	normalize_coord(t_coords coord)
{
	return ((t_coords){.x = floor(coord.x / GRID),
						.y = floor(coord.y / GRID)});
}

t_coords	vector_2points(t_coords p, t_coords q)
{
	return ((t_coords){.x = q.x - p.x, .y = q.y - p.y});
}

t_coords	vector_perp(t_coords v)
{
	return ((t_coords){.x = v.y, .y = -v.x});
}
