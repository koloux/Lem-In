/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:40:21 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 18:14:44 by nhuber           ###   ########.fr       */
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
	int			j;
	long long	nb;

	j = 0;
	while (i > 0 && line[i] != ' ')
	{
		if (ft_isdigit(line[i--] == 1))
			return (-1);
		j++;
	}
	nb = ft_atol(line + i);
	if (i == 0 || j > 11 || nb > 2147483647 || nb < -2147483648)
		return (-1);
	return (j);
}

int	is_room(t_vector *anthill, char *line)
{
	int	len_x;
	int	len_y;
	int	id;

	len_x = 0;
	id = 0;
	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	if ((len_y = is_coordinate(line, (int)ft_strlen(line))) > 0)
	{
		if ((len_x = is_coordinate(line, (int)ft_strlen(line) - len_y - 1)) > 0)
		{
			id = is_duplicatecoordinate(anthill, line, len_x, len_y);
			id += (id == 0) ? is_name(anthill, line, (int)ft_strlen(line) -
				(len_x + len_y + 1)) : -1;
		}
	}
	if (id < 0 || len_x <= 0 || len_y <= 0)
		return (-1);
	return (0);
}

int	is_name(t_vector *anthill, char *line, int len)
{
	int		i;

	i = 0;
	while (i <= len && i != -1)
	{
		if (line[i++] == '-')
			i = -1;
	}
	i = (i == -1) ? -1 : is_duplicatename(anthill, line, len);
	return ((i == -1) ? -1 : 0);
}
