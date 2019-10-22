/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:28:30 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/09 21:01:07 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int aux;

	i = 0;
	while (i < size - 1)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			aux = *(tab + i);
			*(tab + i) = *(tab + i + 1);
			*(tab + i + 1) = aux;
			i = 0;
		}
		i++;
	}
}
