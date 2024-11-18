/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:51:15 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 10:51:16 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_setarray(int len, char *output, const char *hex, unsigned long ptr)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		output[2 + i] = hex[ptr % 16];
		ptr /= 16;
		i--;
	}
}

int	ft_p_printf(void *pointer)
{
	const char		*hex = "0123456789abcdef";
	unsigned long	cast_ptr;
	int				len;
	char			output[20];

	cast_ptr = 0;
	len = 0;
	if (!pointer)
		return (write(1, "(nil)", 5));
	else
	{
		output[0] = '0';
		output[1] = 'x';
		cast_ptr = (unsigned long)pointer;
		len = ft_nbrlen_hex(cast_ptr);
		ft_setarray(len, output, hex, cast_ptr);
		output[2 + len] = '\0';
	}
	ft_putstr_fd(output, 1);
	return (len + 2);
}
