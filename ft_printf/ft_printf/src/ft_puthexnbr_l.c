/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:56:05 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/17 16:56:06 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthexnbr_l(unsigned int n)
{
	char		c;
	const char	*hex = "0123456789ABCDEF";

	if (n > 0xf)
	{
		ft_puthexnbr_l(n / 16);
	}
	c = hex[n % 16];
	write(1, &c, 1);
	return ;
}
