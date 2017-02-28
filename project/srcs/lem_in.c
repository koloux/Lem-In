/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 12:57:27 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_vector	*anthill;

	(void)av;
	if (ac != 2)
		print_usage(2);
	else
	{
		anthill = vector_construct(4);
		params(av[1], anthill);
		printf("\n\n\n%s", anthill->items[0]);
		//vector_destruct(anthill, &room_destruct);
	}
	return (0);
}

/*

		room_tubes(anthill);
		room_link(anthill, "Salut-Mon");
		room_link(anthill, "T'-Aime");
		room_link(anthill, "Mon-Ami");
		room_link(anthill, "Je-Mon");
		char	*room[2];
		room[0] = "Salut";
		room[1] = "Mon";
		printf("%d\n", is_duplicatetube(anthill, room));
*/

/*
   int i;
   i = 1;
   while (i < anthill->size)
   {
   node = anthill->items[i];
   printf("%s\n", node->name);
   i++;
   }
   */
