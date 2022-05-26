/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:20:55 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/26 19:58:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_dinner(t_dinner *dinner)
{
	sem_close(dinner->sem_print);
	sem_close(dinner->sem_dead);
	sem_close(dinner->sem_forks);
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_dead");
}
