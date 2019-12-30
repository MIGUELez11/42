/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:16 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/30 16:51:13 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	fix_sizes(current node, old buffer_size,\n position)
**
**	fix_sizes recalculates line_max_size for a much effective
**	memmory allocation, and sets the buffer_size and buffer_max_size
**	to the new values (old buffer_size - \n position
*/

static void		fix_sizes(t_fd_lst *this, ssize_t i, ssize_t npos)
{
	if ((this->line_max_size + npos) / 2 > BUFFER_SIZE)
		this->line_max_size = (this->line_max_size + npos) / 2;
	this->buffer_size = i - npos - 1;
	this->buffer_max_size = i - npos - 1;
}

/*
**	split_buffer(current node, \n position)
**
**	split_buffer takes the buffer and generates the returning line
**	then saves the non-returned buffer on the start of buffer.
**	Also is in charge of freeing the previous buffer memory.
**
**	RETURN VALUES:
**		NULL			: No line was generated
**		Valid Pointer	: A line was generated
*/

static char		*split_buffer(t_fd_lst *this, ssize_t npos)
{
	char		*aux_buf;
	char		*line;
	ssize_t		i;

	line = malloc(sizeof(char) * (npos + 1));
	if (!line)
		return (NULL);
	aux_buf = this->buffer;
	this->buffer = malloc(this->buffer_size - npos + 1);
	if (!this->buffer)
		return (NULL);
	i = 0;
	while (i < npos)
	{
		line[i] = aux_buf[i];
		i++;
	}
	line[i++] = 0;
	while (i++ < this->buffer_size)
		this->buffer[i - npos - 1 - 1] = aux_buf[i - 1];
	fix_sizes(this, i - 1, npos);
	free(aux_buf);
	return (line);
}

/*
**	buffer_realloc(current node)
**
**	buffer_realloc copies the current buffer to a new buffer with more
**	free size on it, then frees the old memory.
**
**	RETURN VALUES:
**		-1	: An error ocurred
**		 1	: Succes
*/

static int		buffer_realloc(t_fd_lst *this)
{
	char	*aux;
	ssize_t	i;

	i = 0;
	aux = this->buffer;
	this->buffer = malloc(this->buffer_size + this->line_max_size);
	if (!this->buffer)
		return (-1);
	this->buffer_max_size = this->buffer_size + this->line_max_size;
	while (i < this->buffer_size)
	{
		this->buffer[i] = aux[i];
		i++;
	}
	free(aux);
	return (1);
}

/*
**	read_line(File descriptor to read, node we are reading from)
**
**	read_line finds a valid line, it checks if there is a valid line stored
**	in the current buffer or if it has to read more, it calls to different
**	reading functions and returns a valid line.
**
**	Returning Values:
**		NULL			: if an error has been produced it returns NULL.
**		Valid pointer	: if a line was read succesfuly returns an
**						  allocated string.
*/

static void		read_line_aux(ssize_t *i, int *nfound, t_fd_lst *this)
{
	while (*i < this->buffer_size && !*nfound)
	{
		if (this->buffer[*i] == '\n'
				|| (this->file_ended && !this->buffer[*i]))
			*nfound = 1;
		(*i)++;
	}
}

char			*read_line(int fd, t_fd_lst *this)
{
	ssize_t	read_size;
	ssize_t	i;
	int		nfound;

	nfound = 0;
	i = 0;
	while (!nfound && !this->file_ended)
	{
		if (this->buffer_max_size - this->buffer_size < BUFFER_SIZE)
		{
			buffer_realloc(this);
			if (!this->buffer)
				return (NULL);
		}
		else
		{
			read_size = read(fd, this->buffer + this->buffer_size, BUFFER_SIZE);
			if (read_size <= 0)
				this->file_ended = (read_size == 0 ? 1 : -1);
			this->buffer_size += read_size;
		}
		read_line_aux(&i, &nfound, this);
	}
	return (split_buffer(this, i - nfound));
}
