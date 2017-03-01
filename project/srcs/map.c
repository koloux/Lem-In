/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:17:41 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 11:03:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_text(t_vector *anthill, char *line)
{
	t_info	*info;
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	str = ft_strjoin(line, "\n");
	info = anthill->items[0];
	if (info->text == NULL)
		info->text = str;
	else
	{
		tmp = info->text;
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		info->text = tmp2;
	}
}
