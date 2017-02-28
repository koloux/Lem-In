/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:19:42 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 16:00:24 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_s_e(t_vector *anthill, int s_e)
{
	t_node	*tmp;

	tmp = anthill->items[anthill->size - 1];
	tmp->s_e = s_e;
}

void	set_weight(t_vector *anthill, int i, int w)
{
	t_node	*tmp;

	tmp = anthill->items[i];
	tmp->weight = w;
}

void	set_prev(t_vector *anthill, int i, int prev)
{
	t_node	*tmp;

	tmp = anthill->items[i];
	tmp->prev = prev;
}
