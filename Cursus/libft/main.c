/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:07:58 by mflorido          #+#    #+#             */
/*   Updated: 2019/11/20 20:07:33 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char            **ft_split2(char const *s, char c);
int main()
{
	char **s = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non ris    us. Suspendisse", ' ');
	int i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}

	printf("\n\n");
	char **r = ft_split2("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non ris    us. Suspendisse", ' ');
	i = 0;
	while (s[i])
	{
		printf("%s\n", r[i]);
		i++;
	}
}
