/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:41:05 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 16:41:09 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_id_printf(int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	ft_putnbr_fd(nbr, 1);
	return (len);
}
