/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:19:39 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/20 20:15:03 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_cub_config *config)
{
	t_list	*node;
	size_t	i;
	size_t	j;
	size_t	length;

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
	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if ((i == 0 || i == length - 1) && config->map[i][j] != '1')
				ft_printf("invalid map %d %d %c\n", i, j, config->map[i][j]);
			else if ((j == 0 || j == ft_strlen(config->map[i]) - 1) &&
			config->map[i][j] != '1')
				ft_printf("invalid map %d %d %c\n", i, j, config->map[i][j]);
			else if (config->map[i][j] != '0' && config->map[i][j] != '1'
			&& config->map[i][j] != '2' && config->map[i][j] != 'N'
			&& config->map[i][j] != 'S' && config->map[i][j] != 'E'
			&& config->map[i][j] != 'W')
				ft_printf("invalid map %d %d %c\n", i, j, config->map[i][j]);
			j++;
		}
		i++;
	}
}
