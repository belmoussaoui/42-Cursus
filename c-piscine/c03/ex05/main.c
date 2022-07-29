/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:48:34 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/18 13:15:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char str1[100] = "hello";
    char str2[100] = "hello";
	char str3[100] = " world";

	printf("strlcat = %lu %s\n", strlcat(str1, str3, 0), str1);
	printf("ft_strlcat = %d %s\n", ft_strlcat(str2, str3, 0), str2);
	printf("\n");

	return 0;
}
