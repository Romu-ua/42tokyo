/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:51:34 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/15 17:51:35 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_zero_m()
{
	char	*output;

	output = (char *)malloc(sizeof(char) * 4);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = 'x';
	output[2] = '0';
	output[3] = '\0';
	return (output);
}
