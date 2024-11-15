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

int	ft_elif_format(char **ptr, va_list *args)
{
		if (**ptr == '%' && *(*ptr + 1) == 'c')
			return (ft_c_printf(ptr, args));
		else if (**ptr == '%' && *(*ptr + 1) == 's')
			ft_s_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'p')
			ft_p_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'd')
			ft_d_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'i')
			ft_i_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'u')
			ft_u_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'x')
			ft_x_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == 'X')
			ft_xX_printf(ptr, args);
		else if (**ptr == '%' && *(*ptr + 1) == '%')
			ft_per_printf(ptr);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char	*ptr;

	va_start(args, format);
	ptr = (char *)format;
	while (*ptr)
	{
		if (ft_elif_format(&ptr, &args))
		{
			write(1, ptr, 1);
			ptr++;
		}
	}
	va_end(args);

	return (0);
}
