/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <ymmthrm15@fuji.waseda.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:08:26 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/01 12:08:27 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-214748364", 12);
		return ;
	}
	else if (n < 0)
	{
		write(fd, '-', 1);
		n = -n;
	}

	if (n > 9)
	{
		n /= 10;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		c = n % 10 + '0';
		write(fd, c, 1);
	}
	return ;
}