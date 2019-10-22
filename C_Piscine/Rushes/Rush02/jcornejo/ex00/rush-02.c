/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:12:48 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/20 23:44:37 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libbasic.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	int		fd;
	char	*dict;
	char	*num;
	int		i;

	if (argc >= 2 && argc <= 3)
	{
		if (argc == 2)
		{
			num  = malloc(sizeof(argv[1]));
			num = argv[1];
			dict = malloc(sizeof("numbers.dict"));
			dict = "numbers.dict";
		}
		else
		{
			num  = malloc(sizeof(argv[2]));
			num = argv[2];
			dict = argv[1];
		}
		fd = open(dict, O_RDONLY);
		if (fd == -1)
		{
			write(1, "Dict Error\n", 12);
		}
		else
		{
			list = ft_assign_memory(dict, 1);
		}
		list = ft_generate_list(dict);
		ft_save_dictionary(dict, list);
		i = 0;
		while (num[i])
			i++;
		ft_split_num(num, i-1, list);
	}
}
