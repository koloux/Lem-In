/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:21:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/24 11:44:11 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	params_tube(int fd, t_vector *anthill)
{
	char	*tube;
	int	er;

	tube = NULL;
	er = 0;
	//malloc anthill->items->tubes : room_tubes(anthill)
	while (er == 0)
	{
		if (get_next_line(fd, &tube) > 0)
		{
			if (is_cmd(tube) == 0)
				map_text(anthill, tube);
			else if (is_tube(anthill, tube) == 0)
			{
				//add to tubes
				//
			}
			else
				er = -1;
		}
		else
			er = -1;

	}
	return (er);
}

static int	params_cmd(int fd, char *line, t_vector *anthill)
{
	char	*room;
	int	er;

	room = NULL;
	er = 0;
	if (is_cmd(line) == 1 || is_cmd(line) == 2)
	{
		er += (is_duplicatecmd(anthill) != 2) ? 0 : -1;
		(er == -1) ? 0 : map_text(anthill, line);
		if (er != -1 && get_next_line(fd, &room) > 0)
		{
			if (is_room(anthill, room) == 0)
			{
				map_text(anthill, room);
				vector_add(anthill, 
						room_construct(get_name(room), is_cmd(line)));
			}
			else
				er = -1;
		}
		else
			er = -1;
	}
	if (is_cmd(line) == 3)
		map_text(anthill, line);
	free(room);
	return (er);
}

static int	params_room(int fd, t_vector *anthill, int antnb)
{
	char	*buff;
	int	er;

	antnb = 3;
	er = 0;
	while (er == 0)
	{
		if (get_next_line(fd, &buff) > 0)
		{
			if (params_cmd(fd, buff, anthill) >= 0)
				er = 0;
			else if (er != -1 && is_room(anthill, buff) >= 0)
			{
				map_text(anthill, buff);
				vector_add(anthill, room_construct(get_name(buff), 0));
			}
			else
				er = -1;
			er += is_duplicatecmd(anthill);
			free(buff);
		}
		else
			er = -1;
	}
	if (er <= 0)
		print_usage(4);
	return (er);
}

static int	params_ant(int fd, t_vector *anthill)
{
	char	*buff;
	int	i;

	buff = NULL;
	i = 0;
	while (i == 0)
	{	
		if (get_next_line(fd, &buff) > 0)
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
		else
			i = -1;
	}
	if (i <= 0)
		print_usage(3);
	return (i);
}

int	params(char *file, t_vector *anthill)
{
	int fd;
	int	antnb;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if ((antnb = params_ant(fd, anthill)) < 0)
			return (-1);
		if (params_room(fd, anthill, antnb) < 0)
			return (-1);
		if (params_tube(fd, anthill) < 0)
			return (-1);
	}
	else
		print_usage(1);
	close(fd);
	return (0);
}
