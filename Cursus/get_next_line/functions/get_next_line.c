/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:16 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/28 13:40:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	lst_init(file descriptor, previouse node)
**
**	lst_init initialize the node to NULL values and sets fd and *prev
**	to the given values and allocates the node.
**
**	returning values:
**		NULL			: Means that an error occured
**		valid pointer	: Node successfuly allocated and initialized.
*/

t_fd_lst	*lst_init(int fd, t_fd_lst *prev)
{
	t_fd_lst	*this;

	this = malloc(sizeof(t_fd_lst));
	if (!this)
		return (NULL);
	this->next = NULL;
	this->buffer = NULL;
	this->fd = fd;
	if (prev)
		prev->next = this;
	this->prev = prev;
	this->buffer_size = 0;
	this->buffer_max_size = 0;
	this->line_max_size = BUFFER_SIZE;
	this->file_ended = 0;
	return (this);
}

/*
**	find_fd_node(current file id, The adress of the pointer to the whole list)
**
**	find_fd_node returns a pointer to the node which we have to use with
**	the current file descriptor.
**		if fd_lst doesn't exists		: it creates a list and a first node,
** 										  then it returns the first node.
**		if a node which the fd exists	: it just return the corresponding
**										  node.
**		if fd_lst exist but fd doesn't	: it creates a new node and returns it.
*/

t_fd_lst	*find_fd_node(int fd, t_fd_lst **fd_lst_adress)
{
	t_fd_lst *this;
	t_fd_lst *prev;

	this = *fd_lst_adress;
	prev = NULL;
	while (this)
	{
		prev = this;
		if (this->fd == fd)
		{
			return (this);
		}
		this = this->next;
	}
	this = lst_init(fd, prev);
	if (!this)
		return (NULL);
	if (!(*fd_lst_adress))
		*fd_lst_adress = this;
	return (this);
}

/*
**	delete_fd_node(The current node, The adress of the pointer to the list)
**
**	delete_fd_node frees the current node memory and if the pointer to the
**	list is equals to the node it sets it to NULL or to the next node.
*/

void		delete_fd_node(t_fd_lst *this, t_fd_lst **fd_lst_adress)
{
	if (this->prev)
		this->prev->next = this->next;
	if (this->next)
		this->next->prev = this->prev;
	if (*fd_lst_adress == this && !this->next)
		*fd_lst_adress = NULL;
	else if (*fd_lst_adress == this && this->next)
		*fd_lst_adress = this->next;
	if (this->buffer)
		free(this->buffer);
	if (this)
		free(this);
}

/*
**	fix_sizes(current node, old buffer_size,\n position)
**
**	fix_sizes recalculates line_max_size for a much effective
**	memmory allocation, and sets the buffer_size and buffer_max_size
**	to the new values (old buffer_size - \n position
*/

void		fix_sizes(t_fd_lst *this, ssize_t i, ssize_t npos)
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

char		*split_buffer(t_fd_lst *this, ssize_t npos)
{
	char	*aux_buf;
	char	*line;
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
	while (i < this->buffer_size)
	{
		this->buffer[i - npos - 1] = aux_buf[i];
		i++;
	}
	fix_sizes(this, i, npos);
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

int			buffer_realloc(t_fd_lst *this)
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

char		*read_line(int fd, t_fd_lst *this)
{
	ssize_t	read_size;
	ssize_t	i;
	int 	nfound;

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
		while (i < this->buffer_size && !nfound)
		{
			if (this->buffer[i] == '\n' || (this->file_ended && !this->buffer[i]))
				nfound = 1;
			i++;
		}
	}
	return (split_buffer(this, i - nfound));
}

/*
**	Used as the Function Call
**
**	get_next_line(where do we read from, where do you want to save the line);
**
**	get_next_line returns an integer, this integer is the error message:
**		 1 : A line has been read.
**		 0 : The end of file has been reached.
**		-1 : An error happened.
*/

int			get_next_line(int fd, char **line)
{
	static t_fd_lst	*fd_lst;
	t_fd_lst		*this;

	this = NULL;
	//printf("fd = %d\n", fd);
	if (fd >= 0)
		this = find_fd_node(fd, &fd_lst);
	else
	{
		if (!*line)
		{
			free(*line);
			*line = NULL;
		}
		return (-1);
	}
	if (!this)
		return (-1);
	*line = read_line(fd, this);
	if (this->file_ended != 0)
	{
		if (!*line && this->file_ended == 0)
		{
			*line = malloc(1);
			if (!*line)
				return (-1);
			*line[0] = 0;
		}
		else if (*line && this->file_ended == -1)
		{
			free(*line);
			*line = NULL;
		}
		delete_fd_node(this, &fd_lst);
		return ((this->file_ended == -1 ? -1 : 0));
	}
	return (1);
}
