/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:41:46 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/12 16:23:29 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strremovechar(const char *str, char c)
{
	int		len;
	int		number_of_c;
	int		i;
	int		j;
	char	*result;

	len = ft_strlen(str);
	i = 0;
	number_of_c = 0;
	while (str[i])
		if (str[i++] == c)
			number_of_c++;
	if (!(result = ft_calloc(len - number_of_c + 1, sizeof(char))))
		cub_exit("Unable to allocate enough memory", ENOMEM, NULL);
	i = 0;
	j = 0;
	while (str[i])
		if (str[i++] != c)
			result[j++] = str[i - 1];
	return (result);
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
		cub_exit("Unable to allocate enough memory", ENOMEM, NULL);
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

int		main(int argc, char **argv)
{
	t_cub_config	config;
	if (argc > 1 && argc < 4 && validate_cub_file(argv[1], &config))
	{
		if (argc == 3 && !ft_strncmp("--save", argv[2], 7))
			config.save = 1;
		else if (argc == 2)
			config.save = 0;
		else
			cub_exit("Invalid argument", EINVAL, &config);
		initialize(&config);
	}
	else
		cub_exit("Not valid map", EINVAL, NULL);
	return (1);
}
