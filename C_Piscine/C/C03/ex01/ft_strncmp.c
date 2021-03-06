/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:41:29 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 15:51:30 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 i < n)
	{
		if (s1[i] != s2[i])
			return 1;
		i++;
	}	
	if (s1[i] - s2[i] < 0 )
		return (-1);
	return (0);
}
