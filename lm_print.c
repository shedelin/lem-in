/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 21:37:09 by shedelin          #+#    #+#             */
/*   Updated: 2014/02/18 21:37:11 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <lem-in.h>

void		lm_print(int num, char *name)
{
	ft_putchar('L');
	ft_putnbr(num);
	ft_putchar('-');
	ft_putstr(name);
}

int			lm_strisint(char *str, int len)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (len == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	else if (len > 10)
		return (0);
	return (1);
}
