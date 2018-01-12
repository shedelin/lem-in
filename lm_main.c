/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:36:34 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:36:36 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

int			main(int ac, char **av)
{
	t_nest		*nest;
	t_room		*end;

	(void)av;
	if (ac != 1)
		lm_error(0);
	nest = lm_get_nest();
	ft_putendl("");
	end = nest->rooms;
	while (end && end->property != END)
		end = end->next;
	while (end && end->state != nest->nb_ants)
	{
		if (lm_move_ants(nest->ants, nest->pipes) == 0)
			break ;
		ft_putchar('\n');
	}
	return (0);
}
