/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/18 13:32:12 by nhuber           ###   ########.fr       */
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
		char *s = "HelloBitch -458 -458";
		anthill = vector_construct(4);
		vector_add(anthill, &s);
		vector_add(anthill, room_construct("Hello", 1, 3));
		vector_add(anthill, room_construct("World", 1, 5));
		vector_add(anthill, room_construct("I", 1, 3));
		vector_add(anthill, room_construct("LOVE", 1, 3));
		vector_add(anthill, room_construct("YOU", 1, 3));
		vector_add(anthill, room_construct("HelloBitch", 1, 3));
		int x = is_coordinate(s, (int)ft_strlen(s));
		int y = is_coordinate(s, (int)ft_strlen(s) - x - 1);
		int z = is_name(anthill, s, (int)ft_strlen(s) - (x + y + 1));
		printf("%d", z);
		//params(av, anthill);
	}
	return (0);
}
