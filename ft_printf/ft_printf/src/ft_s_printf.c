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

int	ft_s_printf(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (len);
}
