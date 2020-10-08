/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:48:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/08 17:55:27 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

void	set_cub_config_value(char **value, t_cub_config *config)
{
	if (!ft_strncmp(value[0], "R", 1))
	{
		config->resolution[0] = ft_atoi(value[1]);
		config->resolution[1] = ft_atoi(value[2]);
		config->resolution_set = 1;
	}
	else if (!ft_strncmp(value[0], "NO", 2) ||
				!ft_strncmp(value[0], "SO", 2) ||
				!ft_strncmp(value[0], "WE", 2) ||
				!ft_strncmp(value[0], "EA", 2) ||
				!ft_strncmp(value[0], "S", 1))
		set_sprites(value[0], value[1], config);
	else if (!ft_strncmp(value[0], "F", 1) || !ft_strncmp(value[0], "C", 1))
		set_colors(value[0], value[1], config);
}

void	get_cub_config_value(char **line, t_cub_config *config)
{
	char	**splitted;
	char	*word[2];
	int		words;

	if (*line && *line[0])
	{
		if (config->north && config->south && config->west && config->east
			&& config->sprite && config->ceiling_set && config->floor_set
			&& config->resolution_set)
			ft_lstadd_back(&config->lst_map,
			ft_lstnew(ft_strdup(*line)));
		else
		{
			word[0] = ft_strtrim(*line, " ");
			word[1] = ft_removeduplicates(word[0], " ");
			splitted = ft_split(word[1], ' ');
			words = 0;
			set_cub_config_value(splitted, config);
			ft_freedouble((void **)splitted);
			free(word[0]);
			free(word[1]);
		}
	}
	if (*line)
		free(*line);
}

void	get_cub_config(int fd, t_cub_config *config)
{
	char			*line;

	setup_config(config);
	while (get_next_line(fd, &line))
		get_cub_config_value(&line, config);
	get_cub_config_value(&line, config);
	parse_map(config);
}

void	clear_cub_config(t_cub_config *config)
{
	if (config->north)
		free(config->north);
	if (config->south)
		free(config->south);
	if (config->west)
		free(config->west);
	if (config->east)
		free(config->east);
	if (config->sprite)
		free(config->sprite);
	if (config->map)
		ft_freedouble((void **)config->map);
}
