/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:56:14 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 13:01:31 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*room_construct(char *name, int s_e)
{
	t_node	*room;

	if ((room = (t_node*)malloc(sizeof(t_node))) != NULL)
	{
		room->name = name;
		room->tubes = NULL;
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
	int		i;
	int		j;

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

void	room_link(t_vector *anthill, char *tube)
{
	int		i;
	int		j;
	char	**rooms;
	t_node	*tmp;

	if ((rooms = ft_strsplit(tube, '-')) != NULL)
	{
		i = get_room_index(anthill, rooms[0]);
		j = get_room_index(anthill, rooms[1]);
		tmp = anthill->items[i];
		tmp->tubes[j] = 1;
		tmp = anthill->items[j];
		tmp->tubes[i] = 1;
	}
}
