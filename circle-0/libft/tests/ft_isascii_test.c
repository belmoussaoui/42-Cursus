/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:57:46 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 16:53:05 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void    ft_isascii_test()
{
    int    test1;
    char    test2;

	test1 = 343;
	test2 = 'a';
	printf("ft_isascii :");
	printf(" ");
	check_assert(ft_isascii(test1) == isascii(test1));
	printf(" | ");
	check_assert(ft_isascii(test2) == isascii(test2));
	printf("\n");
}