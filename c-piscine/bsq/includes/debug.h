/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:56:53 by lrondia           #+#    #+#             */
/*   Updated: 2021/11/30 03:15:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "data_manager.h"
# include <stdio.h>

void	print_data(t_data data);
void	print_tab(int *tab, int lines, int columns);
void	initialize_map(t_data *data);

#endif