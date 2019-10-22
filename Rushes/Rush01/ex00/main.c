/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:56:11 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/13 23:56:01 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Principal function, it receives the arguments
** fwork = outer numbers chart = inside numbers
*/
int g_error_2 = 0;

int		ft_error(void);

/*
** Assigns the memory space to a pointer
** simulating an array[4][4]. This adress
** is returned
*/

char	**ft_assign_memory(void)
{
	int		i;
	char	**pd;

	i = 0;
	pd = malloc(4 * 8);
	while (i < 4)
		pd[i++] = malloc(4);
	return (pd);
}

/*
** We get the input from the prompt and we are
** saving it on a pointer with [4][4] malloc
*/

char	**ft_save_input(char *p)
{
	int		i;
	char	**fwork;

	fwork = ft_assign_memory();
	i = 0;
	while (p[i] != 0)
	{
		if (i % 2 == 1 && p[i] != ' ' && i <= 31)
			ft_error();
		else if (i % 2 == 0 && p[i] > '0' && p[i] < '5' && i <= 31)
			fwork[(i / 2) / 4][(i / 2) % 4] = p[i];
		else if (i % 2 == 0 && (p[i] < '1' || p[i] > '4') && i <= 31)
			ft_error();
		i++;
	}
	if (i != 31)
		ft_error();
	return (fwork);
}

void	ft_draw_chart(char **chart)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &chart[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_comp_errors(char **fw);

char	**ft_place_stuff(char **fw, char **chart);

int		main(int n_args, char **args)
{
	char **fwork;
	char **chart;

	if (n_args == 2)
	{
		fwork = ft_assign_memory();
		chart = ft_assign_memory();
		fwork = ft_save_input(args[1]);
		if (!g_error_2)
			g_error_2 = ft_comp_errors(fwork);
		if (g_error_2)
			return (0);
		chart = ft_place_stuff(fwork, chart);
		ft_draw_chart(chart);
	}
}
