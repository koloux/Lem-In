/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:45:52 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 14:55:28 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_nb(char *line, int len_x, int len_y)
{
	char	*str;
	int		y;
	int		len;
	int		i;

	if ((str = ft_strnew((len_x > len_y) ? len_x : len_y)) == NULL)
		return (-1);
	len = (int)ft_strlen(line);
	i = 0;
	while (i < len_y)
	{
		str[i] = line[i + (len - (len_x + len_y))];
		i++;
	}
	str[i] = '\0';
	y = ft_atoi(str);
	free(str);
	return (y);
}

char	*get_name_room(char *line)
{
	int		i;
	int		j;
	char	*name;

	i = (int)ft_strlen(line);
	j = 0;
	while (j < 2 && i >= 0)
		j += (line[i--] == ' ') ? 1 : 0;
	if ((name = ft_strnew(i + 1)) != NULL)
		ft_strncpy(name, line, i + 1);
	return (name);
}

int		get_room_index(t_vector *anthill, char *name)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i < anthill->size)
	{
		tmp = anthill->items[i];
		if (ft_strcmp(tmp->name, name) == 0)
			return (i);
		i++;
	}
	return (0);
}

int		get_se_index(t_vector *anthill, int se)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (++i < anthill->size)
	{
		tmp = anthill->items[i];
		if (tmp->s_e == se)
			return (i);
	}
	return (0);
}

int		get_pathlen(t_vector *anthill)
{
	t_node	*tmp;
	int		len;
	int		i;

	tmp = anthill->items[get_se_index(anthill, 2)];
	len = 0;
	i = 0;
	while (i != get_se_index(anthill, 1))
	{
		i = tmp->prev;
		tmp = anthill->items[i];
		len++;
	}
	return (len);
}
