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

int	ft_xX_printf(char **ptr, va_list *args)
{
	int			num;
	int			len;
	char		*output;
	const char	*hex = "0123456789ABCDEF";

	num = va_arg(*args, int);
	len = 0;
	if (!num)
		output = ft_zero_m();
	else
	{
		len = ft_nbrlen_hex(num);
		output = (char *)malloc(sizeof(char) * (len + 3));
		if (!output)
			return (0);
		output[0] = '0';
		output[1] = 'x';
		output[2 + len] = '\0';
		while (len >= 0)
		{
			output[2 + len - 1] = hex[num % 16];
			num /= 16;
			len--;
		}
	}
	ft_putstr_fd(output, 1);
	(*ptr) += 2;
	return (0);
}
