/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:29:08 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/17 09:34:50 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int isalpha;

	i = 0;
	while (str[i] != 0)
	{
		isalpha = 0;
		if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			isalpha = 1;
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			isalpha = 1;
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
			isalpha = 1;
		else
			isalpha = 0;
		if ((!isalpha || i == 0) && str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		if ((isalpha) && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}
