/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:03:17 by lrondia           #+#    #+#             */
/*   Updated: 2021/11/30 05:36:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <unistd.h>
# include "utils.h"
# include "position.h"
# include "data_manager.h"

void	process(t_data data);
int		*create_score(t_data data);
void	set_score(t_data data, int *score);
void	print_res(t_data data);
void	set_biggest_square(t_data *data, int *score, int best);

#endif