/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:12:41 by hyamamot          #+#    #+#             */
/*   Updated: 2024/11/13 21:12:42 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>

#include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_c_printf(char **ptr, va_list *args);
int		ft_s_printf(char **ptr, va_list *args);
int		ft_p_printf(char **ptr, va_list *args);
int		ft_d_printf(char **ptr, va_list *args);
int		ft_i_printf(char **ptr, va_list *args);
int		ft_u_printf(char **ptr, va_list *args);
int		ft_x_printf(char **ptr, va_list *args);
int		ft_xX_printf(char **ptr, va_list *args);
int		ft_per_printf(char **ptr);

int		ft_nbrlen_hex(int num);
void	ft_zero(char *output);
char	*ft_zero_m();

#endif
