/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:13:15 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/17 16:13:17 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthexnbr(unsigned int n)
{
	char		c;
	const char	*hex = "0123456789abcdef";

	if (n > 0xf)
		ft_puthexnbr(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
	return ;
}
