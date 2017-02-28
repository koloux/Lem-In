/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:10:35 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 17:52:37 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		solve(t_vector *anthill)
{
	int		s;
	int		w;
	int		i;
	t_node	*tmp;

	w = 1;
	s = get_se_index(anthill, 1);
	set_weight(anthill, s, w);
	tmp = anthill->items[s];
	while (w < anthill->size)
	{
		i = 0;
		while (++i < anthill->size)
		{
			tmp = anthill->items[i];
			if (tmp->weight == w)
				set_weight(anthill, i, w + 1);
		}
		w++;
	}
	return (0);
}
