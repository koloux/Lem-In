/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:49:24 by nhuber            #+#    #+#             */
/*   Updated: 2016/07/01 17:52:18 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_delone(t_vector *v, int index, void (*del)(void *))
{
	if (index < 0 || index > v->size)
		return ;
	del(v->items[index]);
	while (index < v->size - 1)
	{
		v->items[index] = v->items[index + 1];
		index++;
	}
	v->items[v->size--] = NULL;
}
