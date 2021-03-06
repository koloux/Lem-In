/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:48:02 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 19:03:07 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	read_file(t_vector *anthill, int fd)
{
	int		antnb;
	int		er;
	char	*buff;

	er = 0;
	antnb = 0;
	buff = NULL;
	while (antnb >= 0 && er != -1 && get_next_line(fd, &buff) > 0)
	{
		if (is_cmd(buff) >= 0)
			er = params_cmd(fd, buff, anthill);
		else if (antnb == 0)
			antnb = params_ant(buff, anthill);
		else if (antnb > 0 && params_room(buff, anthill) >= 0)
			er = 1;
		else if (antnb > 0 && params_tube(buff, anthill) >= 0)
			er = 2;
		else
			er = -1;
		free(buff);
		buff = NULL;
	}
	if (buff != NULL)
		free(buff);
	return (er);
}
