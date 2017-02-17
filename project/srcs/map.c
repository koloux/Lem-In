/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:41 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:25:03 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_text(t_vector *anthill, char *line)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	str = ft_strjoin(line, "\n");
	if (anthill->size == 0)
	{
		anthill->items[0] = str;
		anthill->size = 1; 
	}
	else
	{
		tmp = anthill->items[0];
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		anthill->items[0] = tmp2;
	}
}
