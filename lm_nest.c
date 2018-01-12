/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_nest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:37:59 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:38:01 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <lem-in.h>
#include <libft.h>
#include <get_next_line.h>
#include "lem-in.h"

static int		lm_add_line(t_nest *nest, char *line);
static void		lm_room_pipe(t_nest *nest, char *line, char **property);
static t_nest	*lm_nestnew(void);

t_nest			*lm_get_nest(void)
{
	t_nest	*nest;
	char	*line;

	line = NULL;
	nest = lm_nestnew();
	get_next_line(0, &line);
	if (!lm_test_ants(line) || ft_atoi(line) == 0 || !line)
		lm_error(7);
	nest->nb_ants = ft_atoi(line);
	ft_putendl(line);
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (lm_add_line(nest, line))
			break ;
	}
	if (lm_check(nest))
		nest->ants = lm_init_ants(nest->nb_ants, nest);
	return (nest);
}

static int		lm_add_line(t_nest *nest, char *line)
{
	static char		*property = NULL;

	if (line == NULL)
		return (1);
	else if (*line == 'L')
		return (1);
	else if ((*line == '#' && *(line + 1) == '#'))
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		{
			property = ft_strdup(line + 2);
			if (lm_check_rules(nest))
				return (1);
		}
		else
			return (0);
	}
	else if (*line == '#' && *(line + 1) != '#')
		return (0);
	else
		lm_room_pipe(nest, line, &property);
	return (0);
}

static void		lm_room_pipe(t_nest *nest, char *line, char **property)
{
	static int		i = 0;

	if (lm_test_room(nest, line) && i == 0)
		lm_add_room(nest, line, property);
	else
	{
		i = 1;
		if (lm_test_pipe(nest->rooms, line) && nest->rooms)
			lm_add_pipe(nest, line, property);
	}
}

static t_nest	*lm_nestnew(void)
{
	t_nest	*new;

	if (!(new = (t_nest *)malloc(sizeof(t_nest))))
		lm_error(2);
	new->ants = NULL;
	new->rooms = NULL;
	new->pipes = NULL;
	new->coords = NULL;
	return (new);
}
