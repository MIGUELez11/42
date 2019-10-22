/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprendizaje.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:03:28 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/05 18:46:38 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	main(void)
{

	char c;
	short int i;
	float f;
	double d;	
	int j;
	char ArrC[2];
	ArrC[0]='l';
	ArrC[1]='o';
	write(1, &c,1);
	i = -1;
	while (++i < 10) {
		j = -1;
		while(j++ < 10) {
			printf("i = %d; j = %d\n", i, j);
		}	
	}
	
	return(0);
}

