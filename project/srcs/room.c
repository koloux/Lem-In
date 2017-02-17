/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:56:14 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:53:09 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*room_construct(char *name)
{
	t_node	*room;

	if ((room = (t_node*)malloc(sizeof(t_node))) != NULL)
	{
		room->name = ft_strdup(name);
		room->s_e = -1;
		room->weight = -1;
	}
	return (room);
}

void	room_destruct(t_node *room)
{
	free(room->name);
	free(room);
}
