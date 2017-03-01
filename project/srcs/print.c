/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:53:03 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 13:03:46 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_usage(int error)
{
	if (error != -1)
		ft_putendl("ERROR");
	if (error == -2)
	{
		ft_putendl("\tWrong number of arguments");
		error = 0;
	}
	if (error == 0)
		ft_putendl("\tUsage : ./lem_in <file_name>");
	if (error == 1)
		ft_putendl("\tWrong phase 1 : Ants Number");
	if (error == 2)
		ft_putendl("\tWrong phase 2 : Rooms");
	if (error == 3)
		ft_putendl("\tWrong phase 3 : Tube");
	if (error == 4)
		ft_putendl("\tWrong phase cmd");
}

void	print_path(t_vector *anthill)
{
	int		max;
	t_info	*info;

	max = get_pathlen(anthill);
	info = anthill->items[0];
	while (info->antnb > 0)
	{
		

	}
}
