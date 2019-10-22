/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:43:43 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/20 17:31:49 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int		ft_get_dictionary_length(char *dictionary)
{
	int		fd;
	int		fr;
	char	a;
	int		istrueline;
	int		lines;

	fr = 1;
	istrueline = 0;
	lines = 0;
	fd = open(dictionary, O_RDONLY);
	while (fr)
	{
		fr = read(fd, &a, 1);
		if (istrueline && a == '\n')
		{
			lines++;
		}
		else if (!istrueline && a != '\n' && a != ' ')
		{
			istrueline = 1;
		}
	}
	return (lines);
}

int		ft_g_numl(char *dictionary, int line)
{
	int		fd;
	int		count;
	int		isrealine;
	char	a;

	count = 0;
	isrealine = 0;
	fd = open(dictionary, O_RDONLY);
	while (read(fd, &a, 1) && !(a == ':' && count > line))
	{
		if (a >= '0' && a <= '9')
		{
			if (count >= line)
				count++;
			else
				isrealine = 1;
		}
		else if (a == '\n' && count < line && isrealine)
		{
			count++;
			isrealine = 0;
		}
	}
	close(fd);
	return (count - line);
}

int		ft_g_naml(char *dictionary, int line)
{
	int		fd;
	int		count;
	int		isrealine;
	char	a;

	count = 0;
	isrealine = 0;
	fd = open(dictionary, O_RDONLY);
	while (read(fd, &a, 1) && !(a == '\n' && isrealine && count > line))
	{
		if (a > ' ' && a <= '~')
		{
			if (count >= line && isrealine)
				count++;
			else if (a == ':')
				isrealine = 1;
		}
		else if (a == '\n' && count < line && isrealine)
		{
			count++;
			isrealine = 0;
		}
	}
	close(fd);
	return (count - line);
}
