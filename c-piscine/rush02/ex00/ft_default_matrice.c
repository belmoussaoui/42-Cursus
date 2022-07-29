/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_matrice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:45:16 by llaruell          #+#    #+#             */
/*   Updated: 2021/11/28 13:00:02 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_default_matrice_part1(t_data *data)
{
	data->dict[0] = "zero";
    data->dict[1] = "one";
    data->dict[2] = "two";
    data->dict[3] = "three";
    data->dict[4] = "four";
    data->dict[5] = "five";
    data->dict[6] = "six";
    data->dict[7] = "seven";
    data->dict[8] = "eight";
    data->dict[9] = "nine";
    data->dict[10] = "ten";
    data->dict[11] = "eleven";
    data->dict[12] = "twelve";
    data->dict[13] = "thirteen";
    data->dict[14] = "fourteen";
    data->dict[15] = "fifteen";
    data->dict[16] = "sixteen";
    data->dict[17] = "seventeen";
    data->dict[18] = "eighteen";
    data->dict[19] = "nineteen";
    data->dict[20] = "twenty";
    data->dict[21] = "thirty";
    data->dict[22] = "fourty";
    data->dict[23] = "fifty";
    data->dict[24] = "sixty";
}

void    ft_default_matrice_part2(t_data *data)
{
    data->dict[25] = "seventy";
    data->dict[26] = "eighty";
    data->dict[27] = "ninety";
    data->dict[28] = "hundred";
    data->dict[29] = "thousand";
    data->dict[30] = "million";
    data->dict[31] = "billion";
    data->dict[32] = "trillion";
    data->dict[33] = "quadrillion";
    data->dict[34] = "quintillion";
    data->dict[35] = "sextillion";
    data->dict[36] = "septillion";
    data->dict[37] = "octillion";
    data->dict[38] = "nonillion";
    data->dict[39] = "decillion";
    data->dict[40] = "undecillion";
}

void ft_default_matrice(t_data *data)
{
    ft_default_matrice_part1(data);
    ft_default_matrice_part2(data);
}
