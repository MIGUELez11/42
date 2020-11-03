/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:08:35 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/03 19:36:39 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"
#include "../../minilibx_linux/mlx.h"

void	setup_window(t_cub_config *cfg)
{
	void	*mlx;

	if (OS == 0)
	{
		mlx = mlx_init();
		if (!mlx)
			cub_exit("Can not initialize mlx", ENOMEM, cfg);
		mlx_get_screen_size(mlx, &cfg->max_x, &cfg->max_y);
		mlx_free_mlx_ptr(mlx);
	}
	else
	{
		cfg->max_x = SCREEN_MAX_X;
		cfg->max_y = SCREEN_MAX_Y;
	}
}

void	setup_player(t_cub_config *config)
{
	t_coords	coords;

	coords = (t_coords){.x = 0.0, .y = 0.0};
	config->player = (t_player){.position = coords,
	.velocity = (t_coords){.x = GRID, .y = GRID}, .heading_set = 0,
	.heading = 0};
}

void	setup_config(t_cub_config *config)
{
	config->ceiling_set = 0;
	config->floor_set = 0;
	config->resolution_set = 0;
	config->north = 0;
	config->south = 0;
	config->west = 0;
	config->east = 0;
	config->sprite = 0;
	config->lst_map = 0;
	config->map = 0;
	setup_window(config);
	setup_player(config);
}

void	set_colors(char *position, char *value, t_cub_config *config)
{
	char	**numbers;

	numbers = ft_split(value, ',');
	if (!ft_strncmp(position, "F", 1))
	{
		config->floor[0] = ft_atoi(numbers[0]);
		config->floor[1] = ft_atoi(numbers[1]);
		config->floor[2] = ft_atoi(numbers[2]);
		config->floor_set = 1;
	}
	else
	{
		config->ceiling[0] = ft_atoi(numbers[0]);
		config->ceiling[1] = ft_atoi(numbers[1]);
		config->ceiling[2] = ft_atoi(numbers[2]);
		config->ceiling_set = 1;
	}
	ft_freedouble((void **)numbers);
}

void	set_sprites(char *position, char *value, t_cub_config *config)
{
	if (!check_extension(value, "xpm"))
		cub_exit("Invalid image extension. Only .xpm accepted", EINVAL, config);
	if (open(value, O_RDONLY) == -1)
		cub_exit("Image does not exist", EEXIST, config);
	if (!ft_strncmp(position, "NO", 2) && !config->north)
		config->north = ft_strdup(value);
	else if (!ft_strncmp(position, "SO", 2) && !config->south)
		config->south = ft_strdup(value);
	else if (!ft_strncmp(position, "WE", 2) && !config->west)
		config->west = ft_strdup(value);
	else if (!ft_strncmp(position, "EA", 2) && !config->east)
		config->east = ft_strdup(value);
	else if (!ft_strncmp(position, "S", 1) && !config->sprite)
		config->sprite = ft_strdup(value);
}
