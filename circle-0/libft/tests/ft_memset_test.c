/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:10:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 17:59:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void    ft_memset_test()
{
    char    test1[6] = "hello";
	printf("ft_memset :");
	printf(" ");
    check_assert(ft_memset(test1, 's', 3) == memset(test1, 's', 3));
	
	printf("\n");
}