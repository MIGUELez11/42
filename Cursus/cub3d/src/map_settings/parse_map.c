/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:19:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/24 19:20:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

void	set_player_pos(t_int_coords coords, char facing, t_cub_config *config)
{
	if (ft_strchr("NSEW", config->map[coords.y][coords.x]))
	{
		if (config->player.heading_set)
			cub_exit("The player was invoked multiple times", EINVAL, config);
		printf("\n");
		config->player.position = (t_coords){.x = (float)coords.x,
		.y = (float)coords.y};
		if (facing == 'N')
			config->player.heading = 270 * (M_PI / 180);
		else if (facing == 'S')
			config->player.heading = 90 * (M_PI / 180);
		else if (facing == 'E')
			config->player.heading = 0;
		else if (facing == 'W')
			config->player.heading = 180 * (M_PI / 180);
		if (facing == 'N' || facing == 'S' || facing == 'E' || facing == 'W')
			config->player.heading_set = 1;
	}
}

void	check_borders(t_int_coords coords, int prev_width, int next_width,
t_cub_config *config)
{
	int x;
	int y;

	x = coords.x;
	y = coords.y;
	if (x == 0 || y == 0 || !config->map[y + 1] ||
		config->map[y][x + 1] == ' ' || config->map[y][x + 1] == '\0' ||
		config->map[y][x - 1] == ' ' || x > next_width ||
		x > prev_width || config->map[y - 1][x] == ' ' ||
		config->map[y + 1][x] == ' ')
		cub_exit("The map has missing walls", EINVAL, config);
}

int		check_map_integrity(t_cub_config *config)
{
	t_int_coords	coords;
	size_t			prev_width;
	size_t			next_width;

	coords.y = -1;
	while (config->map[++coords.y])
	{
		if (coords.y > 0)
			prev_width = ft_strlen(config->map[coords.y - 1]) - 1;
		if (config->map[coords.y + 1])
			next_width = ft_strlen(config->map[coords.y + 1]) - 1;
		coords.x = -1;
		while (config->map[coords.y][++coords.x])
		{
			if (ft_strrchr("02NSEW", config->map[coords.y][coords.x]))
			{
				check_borders(coords, prev_width, next_width, config);
				set_player_pos(coords, config->map[coords.y][coords.x], config);
			}
		}
	}
	if (!config->player.heading_set)
		cub_exit("The player wasn't invoked at all", EINVAL, config);
	return (1);
}

int		check_invalid_chars(t_cub_config *config)
{
	int i;
	int j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (!ft_strrchr("NSEW012 ", config->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parse_map(t_cub_config *config)
{
	t_list	*node;
	size_t	i;
	size_t	len;

	config->map_height = ft_lstsize(config->lst_map);
	node = config->lst_map;
	if (!(config->map = ft_calloc(config->map_height + 1, sizeof(char *))))
		cub_exit("Unable to allocate enough memory", ENOMEM, config);
	i = 0;
	while (node)
	{
		config->map[i++] = ft_strdup(node->content);
		len = ft_strlen(node->content);
		if (config->map_width < (int)len)
			config->map_width = (int)len;
		node = node->next;
	}
	ft_lstclear(&config->lst_map, free);
	if (!check_map_integrity(config) || !check_invalid_chars(config))
		cub_exit("Invalid map", EINVAL, config);
}
