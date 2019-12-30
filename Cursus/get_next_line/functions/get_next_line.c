/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:29:16 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/30 17:09:39 by mflorido         ###   ########.fr       */
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

static t_fd_lst	*lst_init(int fd, t_fd_lst *prev)
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

static t_fd_lst	*find_fd_node(int fd, t_fd_lst **fd_lst_adress)
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

static void		delete_fd_node(t_fd_lst *this, t_fd_lst **fd_lst_adress)
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
**	Used as the Function Call
**
**	get_next_line(where do we read from, where do you want to save the line);
**
**	get_next_line returns an integer, this integer is the error message:
**		 1 : A line has been read.
**		 0 : The end of file has been reached.
**		-1 : An error happened.
*/

int				get_next_line(int fd, char **line)
{
	static t_fd_lst	*fd_lst;
	t_fd_lst		*this;
	int				return_value;

	this = NULL;
	if (fd >= 0 && line && BUFFER_SIZE > 0)
		this = find_fd_node(fd, &fd_lst);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !this)
		return (-1);
	*line = read_line(fd, this);
	if (this->file_ended != 0)
	{
		if (*line && this->file_ended == -1)
		{
			free(*line);
			*line = NULL;
		}
		return_value = this->file_ended;
		delete_fd_node(this, &fd_lst);
		return ((return_value == -1 ? -1 : 0));
	}
	return (1);
}
