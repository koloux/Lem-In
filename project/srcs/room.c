/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:56:14 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/25 10:49:55 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*room_construct(char *name, int s_e)
{
	t_node	*room;

	if ((room = (t_node*)malloc(sizeof(t_node))) != NULL)
	{
		room->name = name;
		room->s_e = s_e;
		room->weight = -1;
	}
	return (room);
}

void	room_destruct(void *room)
{
	t_node	*tmp;

	tmp = (t_node *)room;
	free(tmp->name);
	free(tmp->tubes);
	free(room);
}

void	room_tubes(t_vector *anthill)
{
	t_node	*tmp;
	char	*tubes;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < anthill->size)
	{
		tmp = anthill->items[i];
		if ((tubes = ft_strnew(anthill->size)) != NULL)
		{
			j = 0;
			while (j < anthill->size)
				tubes[j++] = '0';
			tmp->tubes = tubes;
		}
		i++;
	}
}
