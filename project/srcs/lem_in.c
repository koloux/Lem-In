/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 17:51:37 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	empty(t_vector *anthill)
{
	int		i;
	t_node	*tmp;

	i = 0;
	free(anthill->items[0]);
	while (++i < anthill->size)
	{
		tmp = anthill->items[i];
		room_destruct(tmp);
	}
	free(anthill->items);
	free(anthill);
}

int			main(int ac, char **av)
{
	t_vector	*anthill;

	if (ac != 2)
		print_usage(2);
	else
	{
		anthill = vector_construct(4);
		params(av[1], anthill);
		ft_putstr(anthill->items[0]);
		solve(anthill);
		empty(anthill);
	}
	return (0);
}
