/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:59:57 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 16:53:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void    ft_isprint_test()
{
    int    test1;
    char    test2;

	test1 = 343;
	test2 = 'a';
	printf("ft_isprint_test :");
	printf(" ");
	check_assert(ft_isprint(test1) == isprint(test1));
	printf(" | ");
	check_assert(ft_isprint(test2) == isprint(test2));
	printf("\n");
}