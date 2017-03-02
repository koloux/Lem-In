/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 18:33:53 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	empty(t_vector *anthill, int er)
{
	int		i;
	t_node	*tmp;
	t_info	*info;

	i = 0;
	if (er != -1)
	{
		info = anthill->items[0];
		free(info->text);
		free(anthill->items[0]);
		while (++i < anthill->size)
		{
			tmp = anthill->items[i];
			room_destruct(tmp);
		}
	}
	free(anthill->items);
	free(anthill);
}

int			main(int ac, char **av)
{
	t_vector	*anthill;
	t_info		*info;
	int			er;

	info = NULL;
	anthill = vector_construct(4);
	er = option(ac, av);
	if (er == 1)
		er = option_params(av[2], anthill);
	else
	{
		if (er == 0)
			params(anthill);
	}
	if (er != -1 && solve(anthill) == 0)
	{
		info = anthill->items[0];
		ft_putendl(info->text);
		print_path(anthill);
	}
	empty(anthill, er);
	return (0);
}
