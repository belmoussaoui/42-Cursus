/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:51:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 06:14:31 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_state
{
	int pos;
	int	width;
	int length;
	int is_prefix;
	int is_sign;
	int is_blank;
	int is_left_justify;
	int is_padded_zero;
	int precision;
} t_state;

t_state	initialize_state(void);
void	clear_state(t_state *state);

int		printchar(char c, t_state *state);
int 	printstr(char *str, t_state *state);
int		printnbr(long long int nbr, t_state *state);
int		printhex(unsigned long long int nbr, t_state *state, int (*f)(int));
int 	ft_printf(const char * format, ...);

int		ft_nbrlen(long long int n);
int		ft_hexlen(unsigned long long int n);
void	ft_putlli_fd(long long int n, int fd);
void	ft_puthex_fd(unsigned long long int h, int (*f)(int), int fd);

void	specifier_int(va_list ap, t_state *state);
void	specifier_char(va_list ap, t_state *state);
void	specifier_str(va_list ap, t_state *state);
void	specifier_unsigned(va_list ap, t_state *state);
void	specifier_percentage(t_state *state);
void	specifier_hex(va_list ap, t_state *state, int (*f)(int));
void	specifier_ptr(va_list ap, t_state *state);

void	handle_format(const char *format, va_list ap, t_state *state);

int 	is_flag(char c);
void	set_flag(char c, t_state *state);
void	handle_flags(const char *format, t_state *state);
void 	handle_width(const char *format, t_state *state);
void 	handle_precision(const char *format, t_state *state);

void	debug(t_state *state);

#endif