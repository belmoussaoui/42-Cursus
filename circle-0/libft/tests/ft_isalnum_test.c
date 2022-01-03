/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:53 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 16:53:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_isalnum_test(void)
{
    char    test1;
    char    test2;
    char    test3;

	test1 = 's';
	test2 = '-';
    test3 = '5';
	printf("ft_isalnum :");
	printf(" ");
	check_assert(ft_isalnum(test1) == isalnum(test1));
	printf(" | ");
	check_assert(ft_isalnum(test2) == isalnum(test2));
    printf(" | ");
	check_assert(ft_isalnum(test3) == isalnum(test3));
	printf("\n");
}