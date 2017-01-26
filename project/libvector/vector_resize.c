/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 15:18:11 by nhuber            #+#    #+#             */
/*   Updated: 2016/07/01 15:24:32 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_resize(t_vector *this)
{
	void	**elem;

	if (this->size >= this->capacity)
	{
		if ((elem = (void **)malloc(sizeof(void *) *
						this->capacity * 2)) != NULL)
		{
			items_cpy(elem, this->items, (this->capacity * sizeof(void *)));
			free(this->items);
			this->capacity *= 2;
			this->items = elem;
		}
	}
}
