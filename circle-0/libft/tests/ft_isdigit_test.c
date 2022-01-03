/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:52:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 16:53:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void    ft_isdigit_test()
{
    char    test1;
    char    test2;

	test1 = '7';
	test2 = 'a';
	printf("ft_digit :");
	printf(" ");
	check_assert(ft_isdigit(test1) == isdigit(test1));
	printf(" | ");
	check_assert(ft_isdigit(test2) == isdigit(test2));
	printf("\n");
}