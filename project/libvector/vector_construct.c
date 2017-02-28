/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:41:16 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/22 10:15:32 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_construct(int init_capacity)
{
	t_vector	*v;
	int			c;

	c = init_capacity ? init_capacity : VECTOR_CAPACITY_INIT;
	if (!(v = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(v->items = (void **)malloc(sizeof(void *) * c)))
		return (NULL);
	v->capacity = c;
	v->size = 0;
	return (v);
}
