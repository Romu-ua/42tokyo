/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:05:12 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:05:13 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_u_printf(unsigned int nbr)
{
	int		len;
	char	c;

	len = ft_nbrlen_uns(nbr);
	if (nbr > 9)
		ft_u_printf(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
	return (len);
}
