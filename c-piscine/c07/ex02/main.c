/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:16:34 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/25 13:35:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int **tab;
	ft_ultimate_range(tab, 1, 9);
	for (int i = 0; i < 7; i++)
	{
		printf("%p ", (*tab)[i]);
	}
	
}
