/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:53:03 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/16 13:33:31 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_usage(int error)
{
	ft_putendl("ERROR\n\tUsage : ./lem_in map");
	if (error == 1)
		ft_putendl("\tInvalid File");
	if (error == 2)
		ft_putendl("\tWrong number of arguments");
}
