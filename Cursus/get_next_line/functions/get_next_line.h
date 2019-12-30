/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:34 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/30 17:09:11 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Structure s_fd_lst
** Type t_fd_lst
**
** The structure is used to save each fd information needed for the gnl to
** work.
**
** The variables saved in the structure are used to:
**		fd			: Saves the file binary ID (File Descriptor).
**		*buffer		: The current reading buffer is saved here, it is used
**					  to save the extra information read the last time.
**		buffer_size	: equivalent to strlen(buffer), created for saving
**					  time on any operation that requieres it.
**		*next		: This pointer is the anchor to the next node.
*/

typedef struct		s_fd_lst
{
	int					fd;
	char				*buffer;
	ssize_t				buffer_size;
	ssize_t				buffer_max_size;
	ssize_t				line_max_size;
	int					file_ended;
	struct s_fd_lst		*next;
	struct s_fd_lst		*prev;
}					t_fd_lst;

int					get_next_line(int fd, char **line);
char				*read_line(int fd, t_fd_lst *this);

#endif
