/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:19:42 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 11:05:46 by nhuber           ###   ########.fr       */
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
	t_node	*tmp2;
	int		j;

	j = 0;
	tmp = anthill->items[i];
	while (tmp->tubes[j])
	{
		if (tmp->tubes[j] != '0')
		{
			tmp2 = anthill->items[j];
			if (tmp2->weight == -1 || tmp2->weight > w)
			{
				tmp2->weight = w;
				tmp2->prev = get_room_index(anthill, tmp->name);
			}
		}
		j++;
	}
}

void	set_prev(t_vector *anthill, int i, int prev)
{
	t_node	*tmp;

	tmp = anthill->items[i];
	tmp->prev = prev;
}

void	set_antnb(t_vector *anthill, int antnb)
{
	t_info	*info;

	info = anthill->items[0];
	info->antnb = antnb;
}
