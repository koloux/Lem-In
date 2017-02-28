/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:48:24 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/28 12:17:09 by nhuber           ###   ########.fr       */
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
	char	*tubes;
}			t_node;

/*
 * room : t_node
 */
t_node		*room_construct(char *name, int s_e);
void		room_destruct(void *room);
void		room_tubes(t_vector *anthill);
void		room_link(t_vector *anthill, char *tube);

/*
 * utility / utility2
 */
int			is_antnb(char *line);
int			is_cmd(char *line);
int			is_coordinate(char *line, int i);
int			is_room(t_vector *anthill, char *line);
int			is_name(t_vector *anthill, char *line, int len);
int			is_duplicatename(t_vector *anthill, char *line, int len);
int			is_duplicatecoordinate(t_vector *anthill, char *line,
				int len_x, int len_y);
int			is_duplicatecmd(t_vector *anthill);
int			is_duplicatetube(t_vector *anthill, char **tubes);
int			is_tube(t_vector *anthill, char *tube);

/*
 * get
 */
int			get_nb(char *line, int len_x, int len_y);
char		*get_name_room(char *line);
int			get_room_index(t_vector *anthill, char *name);

/*
 * params : read / open / close
 */
int		params(char *av, t_vector *anthill);

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
