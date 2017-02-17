/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:40:21 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:25:49 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_cmd(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	if (ft_strcmp(line, "##end") == 0)
		return (2);
	if (line[0] == '#')
		return (0);
	return (-1);
}

int	is_antnb(char *line)
{
	long long	nb;
	int			i;

	nb = ft_atol(line);
	i = (int)ft_strlen(line);
	while (i >= 0)
	{
		if (ft_isdigit(line[i--] == 1))
			return (-1);
	}
	if (line[0] == '-' || ft_strlen(line) > 10 || nb > 2147483647 || nb <= 0)
		return (-1);
	return (0);
}

int	is_coordinate(char *line, int i)
{
	int	j;

	j = 0;
	while (i >= 0 && (line[i] != ' ' || line[i] != '-'))
	{
		if (ft_isdigit(line[i--] == 1))
			return (-1);
		j++;
	}
	if (j > 10)
		return (-1);
	j += (line[i] == '-') ? 1 : 0;
	return (j);
}

int	is_room(char *line)
{
	int	len_x;
	int	len_y;

	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	len_x = is_coordinate(line, (int)ft_strlen(line));
	len_y = is_coordinate(line, (int)ft_strlen(line) - len_x - 1);
	if (len_x <= 0 || len_y <= 0)
		return (-1);
	return (0);
}
