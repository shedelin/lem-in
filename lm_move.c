/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:37:03 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:37:05 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

static t_room		*lm_can_move(t_room *pos, t_room *prev, t_pipe *pipes);
static t_room		*lm_check_room(t_room *room, t_room *pos, t_room *prev);
static t_room		*lm_end_near(t_pipe *pipes, t_room *pos);

int					lm_move_ants(t_ant *ants, t_pipe *pipes)
{
	t_room		*next;
	int			res;

	res = 0;
	next = NULL;
	while (ants)
	{
		if ((next = lm_can_move(ants->pos, ants->previous, pipes)))
		{
			if (res++)
				ft_putchar(' ');
			lm_print(ants->num, next->name);
			ants->previous = ants->pos;
			ants->pos->state = ants->pos->state - 1;
			next->state = next->state + 1;
			ants->pos = next;
		}
		ants = ants->next;
	}
	return (res);
}

static t_room		*lm_can_move(t_room *pos, t_room *prev, t_pipe *p)
{
	t_room		*res;

	if (pos->property == END)
		return (NULL);
	if ((res = lm_end_near(p, pos)))
		return (res);
	while (p)
	{
		if (pos == p->room1 && (res = lm_check_room(p->room2, pos, prev)))
			return (res);
		if (pos == p->room2 && (res = lm_check_room(p->room1, pos, prev)))
			return (res);
		p = p->next;
	}
	return (NULL);
}

static t_room		*lm_check_room(t_room *room, t_room *pos, t_room *prev)
{
	if (room->property == END)
		return (room);
	if (pos == room)
		return (NULL);
	if (room->property != START)
	{
		if (room != prev && room->state == EMPTY)
			return (room);
	}
	return (NULL);
}

static t_room		*lm_end_near(t_pipe *pipes, t_room *pos)
{
	while (pipes)
	{
		if (pos == pipes->room1 && pipes->room2->property == END)
			return (pipes->room2);
		if (pos == pipes->room2 && pipes->room1->property == END)
			return (pipes->room1);
		pipes = pipes->next;
	}
	return (NULL);
}
