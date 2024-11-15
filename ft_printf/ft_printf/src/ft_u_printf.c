/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:05:12 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:05:13 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_u_printf(char **ptr, va_list *args)
{
	unsigned int	output;

	output = va_arg(*args, unsigned int);
	ft_putnbr_fd(output, 1);
	(*ptr) += 2;
	return (0);
}
