/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:01:56 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/23 17:44:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_next_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_is_next_prime(2147483646));
	printf("%d\n", ft_is_next_prime(0));
	printf("%d\n", ft_is_next_prime(1));
	printf("%d\n", ft_is_next_prime(2));
	printf("%d\n", ft_is_next_prime(9));
	printf("%d\n", ft_is_next_prime(16));
    printf("%d\n", ft_is_next_prime(13));
	return (0);
}