/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:41:46 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/17 23:35:58 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_provisional
{
	int			resolution[2];
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor[3];
	int			ceiling[3];
}				t_provisional;

/*
** check_extension
**
** If the provided extension matches the filename, then it will
** return true, else it will return false
*/

int		check_extension(char *filename, char *match)
{
	char	**splitted;
	int		words;
	int		match_length;
	int		splitted_length;
	int		length;

	words = 0;
	splitted = ft_split(filename, '.');
	while (splitted[words])
		words++;
	match_length = ft_strlen(match);
	splitted_length = ft_strlen(splitted[words - 1]);
	length = match_length > splitted_length ? match_length : splitted_length;
	words = ft_strncmp(splitted[words - 1], match, length) == 0;
	ft_freedouble((void **)splitted);
	return (words);
}

int		ft_numberofduplicates(const char *str, const char *set)
{
	int i;
	int j;
	int counter;

	i = 1;
	counter = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j] && str[i] == str[i - 1])
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

char	*ft_removeduplicates(const char *str, const char *set)
{
	int		i;
	int		j;
	int		put;
	int		pos;
	char	*result;

	i = -1;
	pos = ft_numberofduplicates(str, set);
	if (!(result = ft_calloc(ft_strlen(str) - pos + 1, sizeof(char))))
		return (result);
	pos = 0;
	while (str[++i])
	{
		j = 0;
		put = 1;
		while (set[j])
		{
			if (str[i] == set[j++] && str[i] == str[i - 1])
				put = 0;
		}
		if (put)
			result[pos++] += str[i];
	}
	return (result);
}

void	set_sprites(char *position, char *value, t_provisional *config)
{
	if (!ft_strncmp(position, "NO", 2))
	{
		config->north = value;
		ft_printf("akjdjksd %s", value);
	}
	else if (!ft_strncmp(position, "SO", 2))
		config->south = value;
	else if (!ft_strncmp(position, "WE", 2))
		config->west = value;
	else if (!ft_strncmp(position, "EA", 2))
		config->east = value;
	else if (!ft_strncmp(position, "S", 1))
		config->sprite = value;
}

void	set_cub_config_value(char **value, t_provisional *config)
{
	if (!ft_strncmp(value[0], "R", 1))
	{
		ft_printf("R: %s %s\n", value[1], value[2]);
		config->resolution[0] = ft_atoi(value[1]);
		config->resolution[1] = ft_atoi(value[2]);
	}
	else if (!ft_strncmp(value[0], "NO", 2)
			|| !ft_strncmp(value[0], "SO", 2)
			|| !ft_strncmp(value[0], "WE", 2)
			|| !ft_strncmp(value[0], "EA", 2)
			|| !ft_strncmp(value[0], "S", 1))
			set_sprites(value[0], ft_strdup(value[1]), config);
	else if (!ft_strncmp(value[0], "F", 1) || !ft_strncmp(value[0], "C", 1))
			ft_printf("%2s: %s\n", value[0], value[1]);
	else
		ft_printf("Error");
	ft_printf("R: %d %d NO: %s\n", config->resolution[0], config->resolution[1], config->south);
}

void get_cub_config_value(char **line, t_provisional *config)
{
	char	**splitted;
	char	*word[2];
	int		words;

	if (*line)
	{
		word[0] = ft_strtrim(*line, " ");
		word[1] = ft_removeduplicates(word[0], " ");
		splitted = ft_split(word[1], ' ');
		words = 0;
		set_cub_config_value(splitted, config);
		ft_freedouble((void **)splitted);
		free(word[0]);
		free(word[1]);
		free(*line);
	}
}

void	get_cub_config(int fd)
{
	t_provisional config;
	char	*line;

	while (get_next_line(fd, &line))
		get_cub_config_value(&line, &config);
	get_cub_config_value(&line, &config);
}

int		validate_cub_file(char *filename)
{
	int	fd;

	if (check_extension(filename, "cub"))
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_printf("file does not exist\n");
		else
		{
			ft_printf("File exists\n");
			get_cub_config(fd);
			close(fd);
		}
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && validate_cub_file(argv[1]))
	{
		ft_printf("valid\n");
	}
	else
		ft_printf("No valid\n");
	ft_printf("\n\n\n\n");
	system("leaks cub3d");
	return (1);
}
