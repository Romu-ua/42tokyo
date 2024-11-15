/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:29:03 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/14 21:29:04 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_s_printf(char **ptr, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	(*ptr) += 2;
	return (0);
}
