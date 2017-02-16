/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:21:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/16 18:04:38 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	params_read(char *file)
{
	int 	fd;
	char	*buff;
	int	er;
	int	i;
	int	se;

	i = 0;
	er = 0;
	se = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &buff) > 0 && er == 0)
		{
			if (i == 0 && er == 0)
			{
				(is_antnb(buff) >= 0 ? printf("we build") : er++);
				//add nb to struct
				i++;
			}
			else if (i == 1 && er == 0)
			{
				se += (se == 0) ? is_cmd(buff) : 0;
				if (is_room(buff) == 0)
				{
					printf("we build with %d opt", se);
					se = 0;
				}
			}
			else
			{
				
				
			}
			printf("---(%s)---\n", buff);
		}
	}
	else
		print_usage(1);
}

void		params(char **av)
{
	params_read(av[1]);
}
