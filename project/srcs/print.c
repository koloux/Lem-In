/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:53:03 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:21:16 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_usage(int error)
{
	ft_putendl("ERROR");
	if (error == 1)
		ft_putendl("\tUsage : ./lem_in <file_name>");
	if (error == 2)
		ft_putendl("\tWrong number of arguments");
	if (error == 3)
		ft_putendl("\tWrong phase 1 : Ants Number");
}
