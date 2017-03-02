/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 22:30:47 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/02 17:45:48 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	option(int ac, char **av)
{
	if (ac > 3 || ac == 2)
	{
		print_usage(-2);
		return (-1);
	}
	if (ac == 3)
	{
		if (ft_strcmp(av[1], "-f") == 0)
			return (1);
		else
			print_usage(5);
		return (-1);
	}
	return (0);
}

int	option_params(char *file, t_vector *anthill)
{
	t_info	*info;
	int		fd;
	int		er;

	er = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if ((info = (t_info *)malloc(sizeof(t_info))) != NULL)
		{
			anthill->items[0] = info;
			info->text = NULL;
			info->antnb = 0;
			anthill->size++;
			read_file(anthill, fd);
		}
	}
	else
	{
		print_usage(0);
		return (-1);
	}
	close(fd);
	return (er);
}
