/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:02 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 14:49:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_isalpha_test(void)
{
	char    test1;
    char    test2;

	test1 = 's';
	test2 = '-';
	printf("ft_isalpha :");
	printf(" ");
	check_assert(ft_isalpha(test1) == isalpha(test1));
	printf(" | ");
	check_assert(ft_isalpha(test2) == isalpha(test2));
	printf("\n");
}