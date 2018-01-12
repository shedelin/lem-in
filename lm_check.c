/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:36:05 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:36:06 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <lem-in.h>

static int		lm_check_start_end(t_nest *nest);
static int		lm_startend_pipe(t_nest *nest);

int				lm_check(t_nest *nest)
{
	if (!nest->rooms)
		lm_error(3);
	if (lm_check_start_end(nest))
		lm_error(4);
	if (!nest->pipes)
		lm_error(5);
	if (lm_startend_pipe(nest))
		lm_error(6);
	return (1);
}

static int		lm_check_start_end(t_nest *nest)
{
	t_room	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = nest->rooms;
	while (tmp)
	{
		if (tmp->property == START)
			start++;
		if (tmp->property == END)
			end++;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
		return (0);
	return (1);
}

static int		lm_startend_pipe(t_nest *nest)
{
	t_pipe	*tmp;
	int		check;

	check = 0;
	tmp = nest->pipes;
	while (tmp)
	{
		if (tmp->room1->property == START || tmp->room1->property == END)
			check++;
		if (tmp->room2->property == START || tmp->room2->property == END)
			check++;
		tmp = tmp->next;
	}
	if (check >= 2)
		return (0);
	return (1);
}

int				lm_check_rules(t_nest *nest)
{
	int		start;
	int		end;
	t_room	*tmp;

	start = 0;
	end = 0;
	tmp = nest->rooms;
	while (tmp)
	{
		if (tmp->property == START)
			start++;
		if (tmp->property == END)
			end++;
		tmp = tmp->next;
	}
	if (start > 1 || end > 1)
		return (1);
	return (0);
}

int				lm_check_coord(t_nest *nest, t_coord *coord)
{
	t_room		*tmp;

	if (!nest->rooms)
		return (1);
	tmp = nest->rooms;
	while (tmp)
	{
		if (coord->x == nest->rooms->x && coord->y == nest->rooms->y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
