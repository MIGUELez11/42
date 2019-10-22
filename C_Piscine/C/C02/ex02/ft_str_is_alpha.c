/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:41:56 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 09:02:42 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int i;
	int upper;
	int lower;

	i = 0;
	while (*(str + i) != 0)
	{
		upper = *(str + i) >= 'A' && *(str + i) <= 'Z';
		lower = *(str + i) >= 'a' && *(str + i) <= 'z';
		if (upper == 0 && lower == 0)
			return (0);
		i++;
	}
	return (1);
}
