/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:44:55 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 15:24:43 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**get_pathname(t_vector *anthill)
{
	char	**path;
	t_node	*tmp;
	int		i;
	int		j;

	j = get_pathlen(anthill);
	if ((path = (char **)malloc(sizeof(char *) * j + 1)) != NULL)
	{
		tmp = anthill->items[get_se_index(anthill, 2)];
		i = 0;
		path[j - 1] = NULL;
		j--;
		while (i != get_se_index(anthill, 1))
		{
			i = tmp->prev;
			path[j--] = ft_strdup(tmp->name);
			tmp = anthill->items[i];
		}
	}
	return (path);
}

long	get_min(long x, long y)
{
	return ((x > y) ? y : x);
}
