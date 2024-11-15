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

int	ft_p_printf(char **ptr, va_list *args)
{
	void			*pointer;
	const	char	*hex = "0123456789abcdef";
	unsigned long	cast_ptr;
	int				len;
	char			output[20];

	cast_ptr = 0;
	pointer = va_arg(*args, void *);
	if (!pointer)
		ft_zero(output);
	else
	{
		output[0] = '0';
		output[1] = 'x';
		cast_ptr = (unsigned long)pointer;
		len = ft_nbrlen_hex(cast_ptr);
		while (len - 1 >= 0)
		{
			output[2 + len - 1] = hex[cast_ptr % 16];
			cast_ptr /= 16;
			len--;
		}
		output[2 + ft_nbrlen_hex((unsigned long)pointer)] = '\0';
	}
	ft_putstr_fd(output, 1);
	(*ptr) += 2;
	return (0);
}
