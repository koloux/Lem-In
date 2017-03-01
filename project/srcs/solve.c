/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:10:35 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 17:17:48 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		solve_path(t_vector *anthill)
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

int				solve(t_vector *anthill)
{
	t_node	*tmp;

	if (error(anthill) != -1)
		return (-1);
	solve_path(anthill);
	tmp = anthill->items[get_se_index(anthill, 2)];
	if (tmp->prev == 0)
	{
		print_usage(3);
		return (-1);
	}
	return (0);
}
