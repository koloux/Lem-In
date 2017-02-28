/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:50:58 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 13:01:39 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_tube(t_vector *anthill, char *tube)
{
	char	**tmp;
	int		er;

	er = 0;
	tmp = ft_strsplit(tube, '-');
	if (tmp[2] != NULL)
		return (-1);
	er += is_duplicatename(anthill, tmp[0], (int)ft_strlen(tmp[0]));
	er += is_duplicatename(anthill, tmp[1], (int)ft_strlen(tmp[1]));
	er = (er == -2) ? 0 : er;
	if (er >= 0)
		er += is_duplicatetube(anthill, tmp);
	return (er);
}
