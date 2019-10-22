/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:09:48 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/13 23:16:49 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_error = 0;

/*
** Prints the error message, only if it was
** never printed before
*/

int		ft_error(void)
{
	if (!g_error)
		write(1, "Error\n", 6);
	g_error = 1;
	return (0);
}

/*
** It if in every visibility line exists a
** a unique visibility of value 1
*/

void	ft_comp_numbers_1(char **fw, char c)
{
	int i;
	int j;
	int cont;

	i = 0;
	while (i < 4)
	{
		j = 0;
		cont = 0;
		while (j < 4)
		{
			if (fw[i][j] == c)
				cont++;
			j++;
		}
		if (cont != 1)
			ft_error();
		i++;
	}
}

/*
** We check all the errors taken from the input, only
** based on the visibilities (1-1) (4-1) (3-3)
*/

int		ft_comp_errors(char **fw)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((fw[0][i] == '1' && fw[1][i] == '1')
				|| (fw[2][i] == '1' && fw[3][i] == '1'))
			ft_error();
		if ((fw[0][i] == '4' && fw[1][i] != '1')
				|| (fw[i][2] == '4' && fw[i][3] != '1'))
			ft_error();
		if ((fw[1][i] == '4' && fw[0][i] != '1')
				|| (fw[3][i] == '4' && fw[2][i] != '1'))
			ft_error();
		if ((fw[0][i] == '3' && fw[1][i] == '3')
				|| (fw[2][i] == '3' && fw[3][i] == '3'))
			ft_error();
		i++;
	}
	ft_comp_numbers_1(fw, '1');
	if (g_error)
		return (1);
	else
		return (0);
}
