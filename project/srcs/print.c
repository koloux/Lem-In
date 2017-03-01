/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:53:03 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 23:00:52 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_move_top(long antnb, long i, long j, char **path)
{
	ft_putchar('L');
	ft_putnbr(j);
	ft_putchar('-');
	ft_putstr(path[i - j]);
	ft_putchar((j == get_min(i, antnb)) ? '\n' : ' ');
}

static void	print_move_bot(t_vector *anthill, long i, long j, char **path)
{
	long	antnb;
	long	max;

	antnb = (long)((t_info *)(anthill->items[0]))->antnb;
	max = (long)get_pathlen(anthill);
	while (i <= max + antnb)
	{
		j = 0;
		while (++j <= get_min(antnb + max - i, max))
		{
			ft_putchar('L');
			ft_putnbr(i - max + j);
			ft_putchar('-');
			ft_putstr(path[max - j]);
			ft_putchar((j == get_min(antnb + max - i, max)) ? '\n' : ' ');
		}
		i++;
	}
}

void		print_path(t_vector *anthill)
{
	t_info	*info;
	long	max;
	char	**path;
	long	i;
	long	j;

	info = anthill->items[0];
	max = (long)get_pathlen(anthill);
	path = get_pathname(anthill);
	i = 1;
	while (i <= max)
	{
		j = 0;
		while (++j <= get_min(i, (long)info->antnb))
			print_move_top((long)info->antnb, i, j, path);
		i++;
	}
	print_move_bot(anthill, i, j, path);
	del_str(path);
}

void		print_usage(int error)
{
	if (error != -1)
		ft_putendl("ERROR");
	if (error == -2)
	{
		ft_putendl("\tWrong number of arguments");
		error = 0;
	}
	if (error == 0)
		ft_putendl("\tUsage : ./lem-in < <file_name>");
	if (error == 1)
		ft_putendl("\tWrong phase 1 : Ants Number");
	if (error == 2)
		ft_putendl("\tWrong phase 2 : Rooms");
	if (error == 3)
		ft_putendl("\tWrong phase 3 : Tube");
	if (error == 4)
		ft_putendl("\tWrong phase cmd");
	if (error == 5)
		ft_putendl("\tUsage : ./lem-in -f <file_name>");
}
