/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:43:33 by llaruell          #+#    #+#             */
/*   Updated: 2021/11/28 08:21:32 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
//Malloc
void	ft_destroy(void)
{
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	ft_error_dict(void)
{
	write(1, "Dict Error\n", 11);
}
