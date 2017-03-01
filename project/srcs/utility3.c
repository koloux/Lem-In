/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:50:58 by nhuber            #+#    #+#             */
/*   Updated: 2017/03/01 18:02:57 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_tube(t_vector *anthill, char *tube)
{
	char	**tmp;
	int		er;
	int		i;

	er = 0;
	i = 0;
	tmp = ft_strsplit(tube, '-');
	if (tmp[2] == NULL)
	{
		er += is_duplicatename(anthill, tmp[0], (int)ft_strlen(tmp[0]));
		er += is_duplicatename(anthill, tmp[1], (int)ft_strlen(tmp[1]));
		er = (er == -2) ? 0 : er;
		if (er >= 0)
			er += is_duplicatetube(anthill, tmp);
	}
	else
		er = -1;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (er);
}

int		is_start_end(t_vector *anthill, int se)
{
	int	i;

	i = get_se_index(anthill, se);
	if (se == 1 && i != 0)
		return (-1);
	if (se == 2 && i != 0)
		return (-1);
	return (0);
}

void	del_str(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] != NULL)
	{
		tmp = s[i];
		ft_strdel(&tmp);
		i++;
	}
	free(s);
}
