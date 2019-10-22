/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:58:50 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/13 23:40:56 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function checks where are the visib. '1'
** placed and on chart places the '4'
*/

void	ft_place_outer_4(char **fw, char **chart)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (fw[0][i] == '1')
			chart[0][i] = '4';
		if (fw[1][i] == '1')
			chart[3][i] = '4';
		if (fw[2][i] == '1')
			chart[i][0] = '4';
		if (fw[3][i] == '1')
			chart[i][3] = '4';
		i++;
	}
}

char	**ft_place_inside_4_3(char **fw, char **chart);

char	**ft_place_rest(char **chart)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (chart[i][j] == 0)
				chart[i][j] = '-';
			j++;
		}
		i++;
	}
	return (chart);
}

char	**ft_place_stuff(char **fw, char **chart)
{
	ft_place_outer_4(fw, chart);
	chart = ft_place_inside_4_3(fw, chart);
	return (ft_place_rest(chart));
}
