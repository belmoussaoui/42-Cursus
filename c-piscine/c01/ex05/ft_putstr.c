/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:00:43 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/13 14:21:35 by bel-mous         ###   ########.fr       */
=======
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:00:43 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/16 21:53:16 by belmouss         ###   ########.fr       */
>>>>>>> 9e341bc4f7220afde8a612d5fae3a8211dcefa8e
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
<<<<<<< HEAD
	while (*str)
=======
	while (*str != '\0')
>>>>>>> 9e341bc4f7220afde8a612d5fae3a8211dcefa8e
	{
		write(1, str, 1);
		str++;
	}
}
