/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:21:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 15:32:51 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	params_tube(char *tube, t_vector *anthill, int er)
{
	int	i;

	i = 0;
	if (er == 1)
		room_tubes(anthill);
	if (is_tube(anthill, tube) == 0)
	{
		map_text(anthill, tube);
		room_link(anthill, tube);
	}
	else
		i = -1;
	return (i);
}

static int	params_room(char *buff, t_vector *anthill)
{
	int	er;

	er = 0;
	if (is_room(anthill, buff) >= 0)
	{
		map_text(anthill, buff);
		vector_add(anthill, room_construct(get_name_room(buff), 0));
	}
	else
		er = -1;
	er += (is_duplicatecmd(anthill) > 2) ? -1 : 0;
	return (er);
}

static int	params_ant(char *buff, t_vector *anthill)
{
	int	i;

	i = 0;
	if (buff[0] == '#' || is_antnb(buff) == 0)
	{
		map_text(anthill, buff);
		i = (is_antnb(buff) == 0) ? ft_atoi(buff) : 0;
	}
	else
		i = -1;
	return (i);
}

static int	params_cmd(int fd, char *line, t_vector *anthill)
{
	char	*room;
	int		er;
	int		cmd;

	room = NULL;
	er = 0;
	cmd = is_cmd(line);
	if (cmd == 1 || cmd == 2)
	{
		er += (is_duplicatecmd(anthill) > 2) ? -1 : 0;
		(er == -1) ? 0 : map_text(anthill, line);
		if (er != -1 && get_next_line(fd, &room) > 0)
		{
			er = params_room(room, anthill);
			if (er == 0)
				set_s_e(anthill, cmd);
		}
		else
			er = -1;
	}
	if (cmd == 0)
		map_text(anthill, line);
	free(room);
	return (er);
}

int			params(char *file, t_vector *anthill)
{
	int		fd;
	int		antnb;
	int		er;
	char	*buff;

	er = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while (er != -1 && get_next_line(fd, &buff) > 0)
		{
			if (is_cmd(buff) >= 0)
				er = params_cmd(fd, buff, anthill);
			else if ((antnb = params_ant(buff, anthill)) > 0)
				er = 3;
			else if (params_room(buff, anthill) >= 0)
				er = 1;
			else if (params_tube(buff, anthill, er) >= 0)
				er = 2;
			else
				er = -1;
			free(buff);
		}
	}
	close(fd);
	return (er);
}
