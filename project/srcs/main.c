/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:17 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:24:27 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_vector	*anthill;

	if (ac != 2)
		print_usage(2);
	else
	{
		anthill = vector_construct(4);
		params(av, anthill);
	}
	return (0);
}
