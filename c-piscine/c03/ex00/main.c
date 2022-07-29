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

int ft_strcmp(char *s1, char *s2);

int main()
{
	char str1[] = "hello";
	char str2[] = "hell";
	char str3[] = "hello world";
	int result;

	result = strcmp(str1, str2);
	printf("strcmp(str1, str2) = %d\n", result);
	result = ft_strcmp(str1, str2);
	printf("ft_strcmp(str1, str2) = %d\n", result);
	printf("\n");

	result = strcmp(str1, str3);
	printf("strcmp(str1, str3) = %d\n", result);
	result = ft_strcmp(str1, str3);
	printf("ft_strcmp(str1, str3) = %d\n", result);
	printf("\n");

	result = strcmp("", "ok");
	printf("strcmp('', 'ok') = %d\n", result);
	result = ft_strcmp("", "ok");
	printf("ft_strcmp('', 'ok') = %d\n", result);
	printf("\n");

	result = strcmp("", "");
	printf("strcmp('', '') = %d\n", result);
	result = ft_strcmp("", "");
	printf("ft_strcmp('', '') = %d\n", result);
	printf("\n");

	result = strcmp("ok", "");
	printf("strcmp('ok', '') = %d\n", result);
	result = ft_strcmp("ok", "");
	printf("ft_strcmp('ok', '') = %d\n", result);
	printf("\n");

	return 0;
}
