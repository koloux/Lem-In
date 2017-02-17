/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:48:24 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 18:22:33 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../libvector/vector.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_node
{
	char	*name;
	int	s_e;
	int	weight;
	int	x;
	int	y;
}			t_node;

/*
 * room : t_node
 */
t_node		*room_construct(char *name);

/*
 * utility
 */
int			is_antnb(char *line);
int			is_cmd(char *line);
int			is_coordinate(char *line, int i);
int			is_room(char *line);

/*
 * params : read / open / close
 */
void		params(char **av, t_vector *anthill);

/*
 * map
 */
void		map_text(t_vector *anthill, char *line);

/*
 * print
 */
void		print_usage(int error);

/*
 * error handling
 */
int			error_arg(int ac);


#endif
