/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:29:21 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/20 14:49:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		validate_cub_file(char *filename)
{
	int fd;

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
