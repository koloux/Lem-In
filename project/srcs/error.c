/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:31:23 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 22:42:22 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error_arg(int ac)
{
	return ((ac > 2) ? -1 : 0);
}

int	error(t_vector *anthill)
{
	t_info	*info;
	int		er;

	er = -1;
	info = anthill->items[0];
	if (info->antnb == 0)
		er = 1;
	else if (anthill->size <= 2)
		er = 2;
	else if (is_duplicatecmd(anthill) != 2)
		er = 4;
	print_usage(er);
	return (er);
}
