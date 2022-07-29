/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:02:04 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/25 22:56:07 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	len = max - min;
	*range = malloc(sizeof(int) * len);
	i = min;
	j = 0;
	while (i < max)
	{
		(*range)[j] = i;
		j++;
		i++;
	}
	return (len);
}
