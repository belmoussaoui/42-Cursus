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

char	*ft_strstr(char *str, char *to_find);

int main()
{
	char str1[100] = "hellop";
    char str2[100] = "lo";

	printf("strstr = %s\n", strstr(str1, str2));
	printf("ft_strstr = %s\n", ft_strstr(str1, str2));
	printf("\n");

	printf("strstr = %s\n", strstr("hello", "dljkdn"));
	printf("ft_strstr = %s\n", ft_strstr("hello", "dljkdn"));
	printf("\n");

	return 0;
}
