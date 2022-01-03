/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:19:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 17:13:35 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include "libft.h"

void	check_assert(int boolean);
void	ft_isalpha_test(void);
void    ft_isdigit_test(void);
void    ft_isalnum_test(void);
void 	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_strlen_test(void);
void    ft_memset_test(void);

#endif