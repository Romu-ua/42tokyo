/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:50:17 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:50:19 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_xx_printf(unsigned int nbr)
{
	int	len;

	len = 0;
	if (!nbr)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		len = ft_nbrlen_hex(nbr);
		ft_puthexnbr_l(nbr);
	}
	return (len);
}
