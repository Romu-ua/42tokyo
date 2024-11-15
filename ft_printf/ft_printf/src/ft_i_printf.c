/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:52 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:03:53 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_i_printf(char **ptr, va_list *args)
{
	int	output;

	output = va_arg(*args, int);
	ft_putnbr_fd(output, 1);
	(*ptr) += 2;
	return (0);
}
