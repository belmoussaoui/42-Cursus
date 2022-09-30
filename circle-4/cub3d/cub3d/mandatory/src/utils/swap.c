/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:54 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/12 16:28:35 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int *a, int *b)
{
	*a = *a ^ *b;
	*b ^= *a;
	*a ^= *b;
}
