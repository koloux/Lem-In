/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 15:08:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/07/01 18:03:50 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_destruct(t_vector *v, void (*del)(void *))
{
	int	i;

	i = v->size;
	if (!v)
		return ;
	while (i >= 0)
	{
		del(v->items[i]);
		i--;
	}
	if (v->items)
		free(v->items);
	free(v);
}
