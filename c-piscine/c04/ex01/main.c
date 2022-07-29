/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:42:31 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/20 22:45:51 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

int	ft_putstr(char *str);

int main()
{
	ft_putstr("hello");
	printf("\n");

	ft_putstr("");
	printf("\n");

	ft_putstr("hello world!\n i'm fine\n");

	return 0;
}