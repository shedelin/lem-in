/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:36:20 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 20:36:21 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		lm_error(int error)
{
	if (error == 0)
		ft_putendl_fd("Usage: ./lem-in < [map].", 2);
	if (error == 1)
		ft_putendl_fd("ERROR", 2);
	if (error == 2)
		ft_putendl_fd("Malloc error.", 2);
	if (error == 3)
		ft_putendl_fd("No room.", 2);
	if (error == 4)
		ft_putendl_fd("No start or end.", 2);
	if (error == 5)
		ft_putendl_fd("No pipe.", 2);
	if (error == 6)
		ft_putendl_fd("No way possible.", 2);
	if (error == 7)
		ft_putendl_fd("Number of ants not here or bad.", 2);
	exit(1);
}
