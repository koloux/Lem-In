/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:40:21 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/16 18:04:40 by nhuber           ###   ########.fr       */
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
		return (3);
	return (0);
}

int	is_antnb(char *line)
{
	int	nb;

	nb = ft_atoi(line);
	if (line[0] == '-' || ft_strlen(line) > 10 || nb == 0)
		return (-1);
	return (0);
}

int	is_room(char *line)
{
	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	return (0);
}
