/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:41:29 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 16:38:24 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] != s2[i])
			break;	
		i++;
	}	
	if (s1[i] - s2[i] < 0)
		return (-1);
	else if (s1[i] - s2[i] > 0)
		return (1);
	else
		return (0);
}
int main()
{
	printf("%d",strcmp("2","1"));
	printf("%d",ft_strcmp("2","1"));

}
