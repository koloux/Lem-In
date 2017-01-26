/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:06:48 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/23 14:53:59 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdio.h>
# include <stdlib.h>
# define VECTOR_CAPACITY_INIT 4

typedef struct	s_vector
{
	void		**items;
	int			capacity;
	int			size;

}				t_vector;

t_vector		*vector_construct(int init_capacity);
void			vector_resize(struct s_vector *v);
void			vector_add(t_vector *v, void *item);
void			vector_delone(t_vector *v, int index, void (*del)(void *));
void			vector_destruct(t_vector *v, void (*del)(void *));

void			*items_cpy(void *dst, const void *src, int size);

#endif
