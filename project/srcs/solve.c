/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:10:35 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 16:01:03 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		solve(t_vector *anthill)
{
	int		s;
	int		i;
	t_node	*tmp;
	t_node	*tmp2;

	s = get_start_index(anthill);
	tmp = anthill->items[s];
	i = 0;
	while (tmp->tubes[i])
	{
		if (tmp->tubes[i] != '0')
		{
			tmp2 = anthill->items[tmp->tubes[i]];
			tmp2->weight = w;
			tmp2->prev = get_room_index(anthill, tmp->name);
		}
		j++;
	}
	return (0);	
}

//on set tout les tmp->tubes a w = 1
//si tmp->tubes[i] != '0'
//alors anthill->items[tmp->tubes]->weight = w 
