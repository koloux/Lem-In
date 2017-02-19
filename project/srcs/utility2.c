/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:01:29 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/19 15:58:30 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_duplicatename(t_vector *anthill, char *line, int len)
{
	char	*name;
	int		i;
	int		er;
	t_node	*tmp;

	i = 1;
	er = 0;
	if ((name = ft_strnew(len)) == NULL)
		return (-1);
	ft_strncpy(name, line, len);
	while (i < anthill->size && er != -1)
	{
		tmp = anthill->items[i];
		if (ft_strcmp(tmp->name, name) == 0)
			er = -1;
		i++;
	}
	free(name);
	return (er);
}

int	is_duplicatecoordinate(t_vector *anthill,
		char *line, int len_x, int len_y)
{
	int		x;
	int		i;
	int 	er;
	t_node	*tmp;

	x = get_nb(line, len_x, len_y);
	er = 0;
	i = 1;
	while (i < anthill->size && er != -1)
	{
		tmp = anthill->items[i];
		if (tmp->x == x)
			er += (tmp->y == get_nb(line, 0, len_y)) ? -1 : 0;
		i++;
	}
	return (er);
}
