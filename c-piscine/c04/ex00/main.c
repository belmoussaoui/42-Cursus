/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:16:59 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/20 22:38:14 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int main()
{
	printf("strlen(\"hello\") = %lu\n", strlen("hello"));
	printf("ft_strlen(\"hello\") = %d\n", ft_strlen("hello"));
	printf("\n");

	printf("strlen(\"\") = %lu\n", strlen(""));
	printf("ft_strlen(\"\") = %d\n", ft_strlen(""));
	printf("\n");

    printf("strlen(\"hello world!\n i'm fine\") = %lu\n", strlen("hello world!\n i'm fine"));
	printf("ft_strlen(\"hello world!\n i'm fine\") = %d\n", ft_strlen("hello world!\n i'm fine"));
	printf("\n");

	return 0;
}