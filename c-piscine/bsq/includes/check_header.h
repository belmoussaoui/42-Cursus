/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:58:39 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/30 19:49:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_HEADER_H
# define CHECK_HEADER_H

# include "data_manager.h"
# include "utils.h"

int	check_header(char *line, t_data *data);
int	set_count_line(char *line, t_data *data, int *i);
int	set_symbols(char *line, t_data *data, int *i);

#endif
