/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:16:22 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/23 20:10:36 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <errno.h>
# include <stdlib.h>

	size_t	ft_strlen(const char *s);
	char	*ft_strcpy(char *dst, const char *src);
	int		ft_strcmp(const char *s1, const char *s2);
	ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
	ssize_t	ft_read(int fd, const void *buf, size_t nbyte);
	char	*ft_strdup(const char *s1);

#endif