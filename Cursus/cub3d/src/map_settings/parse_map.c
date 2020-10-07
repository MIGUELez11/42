/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:19:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/05 12:03:26 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

int		check_borders(t_cub_config *config)
{
	size_t i;
	size_t j;

	i = 0;
	while (config->map[i])
	{
		j = -1;
		while (config->map[i][++j])
		{
			if (config->map[i][j] != '1' && ((i == 0 || !config->map[i + 1]) ||
			j == 0 || config->map[i][j + 1] == '\0'))
				return (0);
			if (ft_strchr("NSEW", config->map[i][j]))
			{
				if (config->player.facing)
					return (0);
				config->player.x = i;
				config->player.y = j;
				config->player.facing = config->map[i][j];
			}
		}
		i++;
	}
	return (config->player.facing != '\0');
}

int		check_invalid_chars(t_cub_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (!ft_strrchr("NSEW012", config->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parse_map(t_cub_config *config)
{
	t_list *node;
	size_t length;
	size_t i;

	length = ft_lstsize(config->lst_map);
	node = config->lst_map;
	if (!(config->map = ft_calloc(length + 1, sizeof(char *))))
		cub_exit("Unable to allocate enough memory", ENOMEM, config);
	i = 0;
	while (node)
	{
		config->map[i++] = ft_strdup(node->content);
		node = node->next;
	}
	ft_lstclear(&config->lst_map, free);
	if (!check_borders(config) || !check_invalid_chars(config))
		cub_exit("Invalid map", EINVAL, config);
}
