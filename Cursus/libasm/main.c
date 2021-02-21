/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:22:14 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/23 21:42:48 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void	print_header(const char *color, const char *str)
{
	size_t	len;
	size_t	slen;
	size_t	half;
	size_t	i;

	if (!str)
		return ;
	len = 78;
	slen = strlen(str);
	if (len - 1 <= slen)
		len = slen + 6;
	half = (len - slen) / 2;
	i = 0;
	if (color)
		printf("%s", color);
	while (i < half)
	{
		printf("=");
		i++;
	}
	printf(" %s ", str);
	i += slen;
	while (i < len)
	{
		printf("=");
		i++;
	}
	printf("\e[0m\n");
}
void	check_strlen(const char *str)
{
	size_t	o_len;
	size_t	f_len;

	printf("\nTest:\n");
	o_len = strlen(str);
	f_len = ft_strlen(str);
	if (f_len == o_len)
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("   Expected: '%ld' to equal: '%ld'\e[0m\n", f_len, o_len);
}

void	check_strcpy(char *dst, const char *src)
{
	char	*o_ret;
	char	*f_ret;
	char	*dst_cpy;
	int		i;

	printf("\nTest:\n");
	o_ret = strcpy(dst, src);
	dst_cpy = strdup(dst);
	i = 0;
	while (dst[i])
	{
		dst[i] = 0;
		i++;
	}
	f_ret = ft_strcpy(dst, src);
	if (dst == f_ret && !strcmp(o_ret, f_ret) && !strcmp(dst, o_ret))
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("   Expected return: '%s' to equal: '%s'\n", f_ret, o_ret);
	printf("   Expected dst: '%s' to equal: '%s'\n", dst, dst_cpy);
	printf("   Expected dst: '%p' to equal return: '%p'\e[0m\n", dst, f_ret);
	free(dst_cpy);
}

void	check_strcmp(const char *str1, const char *str2)
{
	int	o_ret;
	int	f_ret;

	printf("\e[0m\nTest:\n");
	o_ret = strcmp(str1, str2);
	o_ret = (o_ret > 0) - (o_ret < 0);
	f_ret = ft_strcmp(str1, str2);
	if (o_ret == f_ret)
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("   Expected return: '%d' to equal: '%d'\n", f_ret, o_ret);
}

void	check_write(int fd, const void *buff, size_t nbyte)
{
	int	o_ret;
	int	f_ret;

	printf("\e[0m\nTest:\n");
	write(fd, "\e[1;33m", 7);
	write(fd, "Original: '", 11);
	o_ret = write(fd, buff, nbyte);
	write(fd, "'\n", 2);
	perror("Error on original");
	write(fd, "\n42:       '", 12);
	f_ret = ft_write(fd, buff, nbyte);
	write(fd, "'\n", 2);
	perror("Error on 42");
	if (o_ret == f_ret)
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("\n   Expected return: '%d' to equal: '%d'\n", f_ret, o_ret);
}

void	check_read(int fd, char *buff, size_t nbyte)
{
	int		o_ret;
	int		f_ret;
	char	*o_buff;
	int		i;

	printf("\e[0m\nTest:\n");
	write(fd, "\e[1;33m", 7);
	write(fd, "Original: (insert chars ^D) '", 29);
	o_ret = read(fd, buff, nbyte);
	o_buff = strdup(buff);
	i = 0;
	while (buff[i])
	{
		buff[i] = 0;
		i++;
	}
	write(fd, "'\n", 2);
	perror("Error on original");
	write(fd, "\n42: (insert chars ^D)       '", 30);
	f_ret = ft_read(fd, buff, nbyte);
	write(fd, "'\n", 2);
	perror("Error on 42");
	if (o_ret == f_ret && !ft_strcmp(o_buff, buff))
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("\n   Expected return: '%d' to equal: '%d'\n", f_ret, o_ret);
	printf("\n   Expected return: '%s' to equal: '%s'\n", buff, o_buff);
	free(o_buff);
}

int 	main() {
	check_strcmp("bon", "");
	// print_header("\e[1;33m", "Tests for ft_strlen");
	// check_strlen("Hola");
	// check_strlen("Qué tal?");
	// check_strlen("H\0f");
	// check_strlen("J\e[1;33m\e[0m\n\033");
	// check_strlen("Adios\n");
	// check_strlen("Hi!");

	// print_header("\e[1;33m", "Tests for ft_strcpy");
	// {
	// 	char dst[5];
	// 	check_strcpy(dst, "Hola");
	// }
	// {
	// 	char dst[5];
	// 	check_strcpy(dst, "H\0ola");
	// }
	// {
	// 	char dst[3];
	// 	check_strcpy(dst, "");
	// }
	// {
	// 	char dst[27];
	// 	check_strcpy(dst, "Adios carambola\0loca");
	// }

	// print_header("\e[1;33m", "Tests for ft_strcmp");
	// check_strcmp("Hola", "Hola");
	// check_strcmp("Hola", "Ho\0la");
	// check_strcmp("Hola", "HolaQ");
	// check_strcmp("Qué?", "Tal");
	// check_strcmp("Pe\0Pe", "Pe\0Pe el Pepe");
	// check_strcmp("\nEsterno\nCleido\nMastoideo", "\nEsterno\nCleido\nMastoideo");

	// print_header("\e[1;33m", "Tests for ft_write");
	// check_write(1, "Hola", 4);
	// check_write(1, "42 is the best", 14);
	// check_write(1, "Does this work?", 15);
	// check_write(1, "What\0About\0this?", 16);
	// check_write(1, "Does this work?", 2);
	// check_write(-1, "Does this work?", 2);
	// check_write(5, "Does this work?", 2);
	// check_write(1, 0, 2);

	// print_header("\e[1;33m", "Tests for ft_read");
	// {
	// 	char *a = malloc(5);
	// 	check_read(1, a, 5);
	// 	free(a);
	// }
	// {
	// 	char *a = malloc(10);
	// 	check_read(1, a, 10);
	// 	free(a);
	// }
	// {
	// 	char *a = malloc(0);
	// 	check_read(1, a, 0);
	// 	free(a);
	// }

	// print_header("\e[1;33m", "Tests for ft_strdup");
	// {
	// 	char *str = ft_strdup("Hola qué tal estás?");
	// 	printf("%s %p\n", str, str);
	// 	free(str);
	// }

	// system("leaks a.out");
}