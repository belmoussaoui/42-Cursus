/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:02:04 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/25 22:56:57 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	len;
	int	i;
	int	j;

	if (min >= max)
		return (NULL);
	len = max - min;
	res = malloc(sizeof(int) * len);
	i = min;
	j = 0;
	while (i < max)
	{
		res[j] = i;
		j++;
		i++;
	}
	return (res);
}
