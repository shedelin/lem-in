/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:35:43 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:35:45 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <lem-in.h>
#include <libft.h>

static t_ant	*lm_antnew(t_room *room, int nb);
static int		lm_isint(char *line);

int				lm_test_ants(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!lm_isint(line + i))
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '\t')
			return (0);
		i++;
	}
	return (1);
}

t_ant			*lm_init_ants(int nb_ants, t_nest *nest)
{
	t_ant		*new;
	t_ant		*tmp;
	t_room		*tmpr;

	new = NULL;
	tmpr = nest->rooms;
	while (tmpr && tmpr->property != START)
		tmpr = tmpr->next;
	while (nb_ants)
	{
		tmp = new;
		new = lm_antnew(tmpr, nb_ants--);
		new->next = tmp;
	}
	return (new);
}

static t_ant	*lm_antnew(t_room *room, int nb)
{
	t_ant		*new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		lm_error(2);
	new->num = nb;
	new->pos = room;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

static int		lm_isint(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (len >= 10 && ft_strcmp(line, "2147483647") >= 0)
		return (0);
	return (1);
}