/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:51:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/18 11:11:34 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int	conversion_integer(va_list ap);
int	conversion_char(va_list ap);
int	conversion_hexadecimal(va_list ap, int (*f)(int), unsigned long value);
int	conversion_string(va_list ap);
int	conversion_unsigned(va_list ap);
int	eval_format(const char *format, va_list ap);
int ft_printf(const char * format, ...);

#endif