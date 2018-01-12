/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:38:42 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:38:44 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static t_room		*lm_room_chr(t_room *room, char *name);

int					lm_test_pipe(t_room *rooms, char *line)
{
	char		**tab;
	char		*tmp;
	int			i;

	i = 0;
	tmp = line;
	while (*tmp++)
		if (*tmp == '-')
			i++;
	if (i != 1)
		return (0);
	tab = ft_strsplit(line, '-');
	if (ft_tabcount(tab) != 2)
		return (0);
	if (ft_strequ(tab[0], tab[1]))
		return (0);
	if (ft_strchr(tab[0], ' ') || ft_strchr(tab[1], ' '))
		return (0);
	if (tab[1] && tab[2] == NULL)
		if (lm_room_chr(rooms, tab[0]) && lm_room_chr(rooms, tab[1]))
			return (1);
	return (0);
}

void				lm_add_pipe(t_nest *nest, char *line, char **property)
{
	char		**tab;
	t_pipe		*new;
	t_pipe		*tmp;

	tab = ft_strsplit(line, '-');
	if (!(new = (t_pipe *)malloc(sizeof(t_pipe))))
		lm_error(2);
	new->room1 = lm_room_chr(nest->rooms, tab[0]);
	new->room2 = lm_room_chr(nest->rooms, tab[1]);
	new->property = ft_strdup(*property);
	ft_strdel(property);
	tmp = nest->pipes;
	nest->pipes = new;
	nest->pipes->next = tmp;
}

static t_room		*lm_room_chr(t_room *room, char *name)
{
	while (room && !ft_strequ(room->name, name))
		room = room->next;
	return (room);
}
