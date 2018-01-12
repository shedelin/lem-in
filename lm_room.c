/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:39:22 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:39:25 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static void		lm_init_room(t_room *room);
static int		lm_test_coord(char *str);

int				lm_test_room(t_nest *nest, char *line)
{
	t_coord		*coord;
	char		**room;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		lm_error(2);
	if (nest->pipes)
		return (0);
	room = ft_strsplit(line, ' ');
	if (ft_tabcount(room) != 3)
		return (0);
	while (*room[0])
	{
		if (!ft_isalnum(*room[0]))
			return (0);
		room[0]++;
	}
	if (!lm_test_coord(room[1]) || !lm_test_coord(room[2]))
		return (0);
	coord->x = ft_atoi(room[1]);
	coord->y = ft_atoi(room[2]);
	nest->coords = coord;
	if (!lm_check_coord(nest, coord))
		return (0);
	return (1);
}

void			lm_add_room(t_nest *nest, char *line, char **property)
{
	t_room		*room;
	t_room		*tmp;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		lm_error(2);
	lm_init_room(room);
	if (ft_strequ(*property, "start"))
	{
		room->property = START;
		room->state = nest->nb_ants;
	}
	else if (ft_strequ(*property, "end"))
		room->property = END;
	else
		room->property = NONE;
	room->name = ft_strcdup(line, ' ');
	room->x = nest->coords->x;
	room->y = nest->coords->y;
	ft_strdel(property);
	tmp = nest->rooms;
	nest->rooms = room;
	nest->rooms->next = tmp;
}

static int		lm_test_coord(char *str)
{
	if (((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		|| ft_isdigit(*str))
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!lm_strisint(str, ft_strlen(str)))
			return (0);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

static void		lm_init_room(t_room *room)
{
	room->state = EMPTY;
	room->name = NULL;
	room->next = NULL;
	room->x = 0;
	room->y = 0;
}
