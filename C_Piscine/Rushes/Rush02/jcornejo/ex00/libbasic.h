/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbasic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:41:10 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/20 22:45:22 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBASIC_H
# define LIBBASIC_H

typedef struct	s_list
{
	char			*name;
	char			*number;
	struct s_list	*next;
	int				size;
}				t_list;

/*
** lib_get_length.c
*/

int				ft_get_dictionary_length(char *dictionary);
int				ft_g_numl(char *dictionary, int line);
int				ft_g_naml(char *dictionary, int line);

/*
** lib_read_dict.c
*/
t_list			*ft_assign_memory(char *dict, int line);
t_list			*ft_generate_list(char *dict);
void			ft_load_dictionary(char *dict, int line, t_list *node);
void			ft_save_dictionary(char *dict, t_list *first_node);
void			free_memory(t_list *node);

/*
** lib_read_num.c
*/
void			ft_find_coincidence(char *num, int size, t_list *list);
void			ft_split_num(char *num, int size, t_list *list);
int				ft_cmpstr(char *str1, char *str2);

#endif
