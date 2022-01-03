/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:03:36 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/03 21:41:48 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char   *ptr;

    ptr = b;
    while (len-- > 0)
    {
        *ptr = (unsigned char)c;
        ptr++;
    }
    return b;
}
