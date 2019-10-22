/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:08:53 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 13:24:09 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned i;

	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
