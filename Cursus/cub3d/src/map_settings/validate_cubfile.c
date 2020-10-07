/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cubfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:29:21 by mflorido          #+#    #+#             */
/*   Updated: 2020/10/05 12:03:38 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_settings.h"

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

int		validate_cub_file(char *filename, t_cub_config *config)
{
	int fd;

	if (check_extension(filename, "cub"))
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			cub_exit("Map file does not exist", EINVAL, NULL);
		else
		{
			ft_printf("File exists\n");
			get_cub_config(fd, config);
			close(fd);
		}
		return (1);
	}
	cub_exit("Not valid extension for map", EINVAL, NULL);
	return (0);
}
