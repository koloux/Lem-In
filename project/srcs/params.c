/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:21:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:25:51 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
static int	params_cmd(int fd, char *line)
{
	char	*room;

	room = NULL;
	if (is_cmd(line) > 0)
	{
		get_next_line(fd, &room);
		is_room(room);
	}
	return (0);
}
*/

static int	params_ant(int fd, t_vector *anthill)
{
	char	*buff;
	int		i;

	buff = NULL;
	i = 0;
	while (get_next_line(fd, &buff) > 0 && i == 0)
	{
		if (is_cmd(buff) > 0)
			i = -1;
		else if (buff[0] == '#' || is_antnb(buff) == 0)
		{
			map_text(anthill, buff);
			i = (is_antnb(buff) == 0) ? ft_atoi(buff) : 0;
		}
		else
			i = -1;	
		free(buff);
	}
	if (i <= 0)
		print_usage(3);
	return (i);
}

static void	params_read(char *file, t_vector *anthill)
{
	int fd;
	int	antnb;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if ((antnb = params_ant(fd, anthill)) > 0)
		{
			printf("%s", anthill->items[0]);	
		}
	}
	else
		print_usage(1);
}

void		params(char **av, t_vector *anthill)
{
	params_read(av[1], anthill);
}
