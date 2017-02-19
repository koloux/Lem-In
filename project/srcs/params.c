/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:21:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/19 16:29:30 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	params_cmd(int fd, char *line, t_vector *anthill)
{
	char	*room;

	room = NULL;
	if (is_cmd(line) == 1 || is_cmd(line) == 2)
	{
		map_text(anthill, line);
		if (get_next_line(fd, &room) >= 0)
		{
			if (is_room(anthill, room) == 0)
			{
				map_text(anthill, room);
				//TO DO : build room
				//vector_add(anthill, room_construct(get_name(room)));
			}
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (is_cmd(line) == 3)
		map_text(anthill, line);
	return (0);
}

static int	params_room(int fd, t_vector *anthill, int antnb)
{
	char	*buff;
	int		i;

	antnb = 3;
	i = 0;
	while (get_next_line(fd, &buff) > 0 && i == 0)
	{
		if (params_cmd(fd, buff, anthill) < 0)
			i = -1;
		//TO DO : build room
		if (i != -1 && is_room(anthill, buff) >= 0)
		{
			map_text(anthill, buff);
		}
		else
			i = -1;
		free(buff);
	}
	if (i <= 0)//check if start end exists
		print_usage(4);
	return (0);
}

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

static int	params_read(char *file, t_vector *anthill)
{
	int fd;
	int	antnb;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if ((antnb = params_ant(fd, anthill)) < 0)
			return (-1);
		printf("%s", anthill->items[0]);
		if (params_room(fd, anthill, antnb) < 0)
			return (-1);
	}
	else
		print_usage(1);
	close(fd);
	return (0);
}

void		params(char **av, t_vector *anthill)
{
	params_read(av[1], anthill);
}
