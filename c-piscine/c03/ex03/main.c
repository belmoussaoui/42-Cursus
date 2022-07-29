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

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char str1[100] = "hello";
    char str2[100] = "hello";
	char str3[100] = " world";

	printf("strcat = %s\n", strncat(str1, str3, 3));
	printf("ft_strcat = %s\n", ft_strncat(str2, str3, 3));
	printf("\n");

	return 0;
}
