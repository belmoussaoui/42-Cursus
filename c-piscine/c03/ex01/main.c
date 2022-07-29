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

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	char str1[] = "hello";
	char str2[] = "hell";
	char str3[] = "hello world";
	int result;
    int n = 5;

	result = strncmp(str1, str2, n);
	printf("strncmp(str1, str2) = %d\n", result);
	result = ft_strncmp(str1, str2, n);
	printf("ft_strncmp(str1, str2) = %d\n", result);
	printf("\n");

	result = strncmp(str1, str3, n);
	printf("strncmp(str1, str3, n) = %d\n", result);
	result = ft_strncmp(str1, str3, n);
	printf("ft_strncmp(str1, str3, n) = %d\n", result);
	printf("\n");

	result = strncmp("", "ok", n);
	printf("strncmp('', 'ok', n) = %d\n", result);
	result = ft_strncmp("", "ok", n);
	printf("ft_strncmp('', 'ok', n) = %d\n", result);
	printf("\n");

	result = strncmp("", "", n);
	printf("strncmp('', '', n) = %d\n", result);
	result = ft_strncmp("", "", n);
	printf("ft_strncmp('', '', n) = %d\n", result);
	printf("\n");

	result = strncmp("ok", "", n);
	printf("strcmp('ok', '', n) = %d\n", result);
	result = ft_strncmp("ok", "", n);
	printf("ft_strcmp('ok', '', n) = %d\n", result);
	printf("\n");

	return 0;
}
