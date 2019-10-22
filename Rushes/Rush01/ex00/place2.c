/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:05:17 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/13 23:43:57 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_return_row(char **chart, int i, int j)
{
	if (i == 0)
	{
		chart[0][j] = '1';
		chart[1][j] = '2';
		chart[2][j] = '3';
	}
	else if (i == 1)
	{
		chart[3][j] = '1';
		chart[2][j] = '2';
		chart[1][j] = '3';
	}
	else if (i == 2)
	{
		chart[j][0] = '1';
		chart[j][1] = '2';
		chart[j][2] = '3';
	}
	else
	{
		chart[j][3] = '1';
		chart[j][2] = '2';
		chart[j][1] = '3';
	}
	return (chart);
}

char	**ft_place_row_4(char **fw, char **chart)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fw[i][j] == '4')
			{
				chart = ft_return_row(chart, i, j);
			}
			j++;
		}
		i++;
	}
	return (chart);
}

char	**ft_place_inside_4_2(char **fw, char **chart)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 1;
	while (i < 3)
	{
		j = 1;
		while (j < 3)
		{
			if (fw[i++][j++] == '3')
				k++;
		}
	}
	if (k == 0)
	{
		chart[1][1] = '4';
		chart[1][2] = '1';
		chart[2][1] = '1';
		chart[2][2] = '4';
	}
	chart = ft_place_row_4(fw, chart);
	return (chart);
}

/*
** We check if there is a 4 inside the chart and
** it places the symetric one
*/

void	ft_place_inside_4_3c(char **chart)
{
	int i;
	int j;

	i = 1;
	while (i < 3)
	{
		j = 1;
		while (j < 3)
		{
			if (chart[i][j] == '4' && chart[0][j] != '4' && chart[3][j] != '4'
					&& chart[j][0] != '4' && chart[j][3] != '4')
			{
				i = (i == 1 ? 2 : 1);
				j = (j == 1 ? 2 : 1);
				chart[i][j] = '4';
				i = 4;
				j = 4;
			}
			j++;
		}
		i++;
	}
}

/*
** This function checks if there are any '3' on the
** middle columns, and if a 4 is not yet positioned,
** it prints it
*/

char	**ft_place_inside_4_3(char **fw, char **chart)
{
	if (fw[0][1] == '3')
		chart[2][1] = '4';
	if (fw[0][2] == '3')
		chart[2][2] = '4';
	if (fw[1][1] == '3')
		chart[1][1] = '4';
	if (fw[1][2] == '3')
		chart[1][2] = '4';
	if (fw[2][1] == '3')
		chart[1][2] = '4';
	if (fw[2][2] == '3')
		chart[2][2] = '4';
	if (fw[3][1] == '3')
		chart[1][1] = '4';
	if (fw[3][2] == '3')
		chart[2][1] = '4';
	ft_place_inside_4_3c(chart);
	chart = ft_place_inside_4_2(fw, chart);
	return (chart);
}
