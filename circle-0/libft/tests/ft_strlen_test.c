/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:02 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/02 05:11:05 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_strlen_test(void)
{
	char	*test1;

	test1 = "hello world!";
	printf("ft_strlen :");
	printf(" ");
	check_assert(ft_strlen(test1) == strlen(test1));
	printf(" | ");
	check_assert(ft_strlen("") == strlen(""));
	printf("\n");
}
