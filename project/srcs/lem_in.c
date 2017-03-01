/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 12:13:04 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	empty(t_vector *anthill)
{
	int		i;
	t_node	*tmp;
	t_info	*info;

	i = 0;
	info = anthill->items[0];
	free(info->text);
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
	t_info		*info;

	info = NULL;
	if (ac != 2)
		print_usage(-2);
	else
	{
		anthill = vector_construct(4);
		params(av[1], anthill);
		if (solve(anthill) == 0)
		{
			info = anthill->items[0];
			ft_putendl(info->text);
		}
		empty(anthill);
	}
	return (0);
}
