/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:06:42 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:06:43 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_x_printf(unsigned int nbr)
{
	int			len;

	len = 0;
	if (!nbr)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		len = ft_nbrlen_hex(nbr);
		ft_puthexnbr(nbr);
	}
	return (len);
}
