/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:10:25 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/13 21:10:27 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ifel_format(char *ptr, va_list *args)
{
	if (*ptr == 'c')
		return (ft_c_printf(va_arg(*args, int)));
	else if (*ptr == 's')
		return (ft_s_printf(va_arg(*args, char *)));
	else if (*ptr == 'p')
		return (ft_p_printf(va_arg(*args, void *)));
	else if (*ptr == 'd' || *ptr == 'i')
		return (ft_id_printf(va_arg(*args, int)));
	else if (*ptr == 'u')
		return (ft_u_printf(va_arg(*args, unsigned int)));
	else if (*ptr == 'x')
		return (ft_x_printf(va_arg(*args, unsigned int)));
	else if (*ptr == 'X')
		return (ft_xx_printf(va_arg(*args, unsigned int)));
	else if (*ptr == '%')
		return (ft_per_printf());
	write(1, ptr, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptr;
	ssize_t	len;

	len = 0;
	va_start(args, format);
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			len += ft_ifel_format(ptr, &args);
		}
		else
			len += write(1, ptr, 1);
		ptr++;
	}
	va_end(args);
	return (len);
}
