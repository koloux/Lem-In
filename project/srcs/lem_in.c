/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/19 16:02:51 by nhuber           ###   ########.fr       */
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
		char *s = "HelloBitch -2 -11";
		anthill = vector_construct(4);
		vector_add(anthill, &s);
		vector_add(anthill, room_construct("Hello", 1, 3));
		vector_add(anthill, room_construct("World", 1, 5));
		vector_add(anthill, room_construct("I", -11, 3));
		vector_add(anthill, room_construct("LOVE", -21, -11));
		vector_add(anthill, room_construct("YOU", 31, 3));
		vector_add(anthill, room_construct("Hello-Bitch", 41, 3));
		int z = is_room(anthill, s);
		printf("ret : %d\n", z);
		//params(av, anthill);
	}
	return (0);
}
