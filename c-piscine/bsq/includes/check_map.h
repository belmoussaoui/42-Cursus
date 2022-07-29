/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:47 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/30 17:58:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include "data_manager.h"
# include "utils.h"

int	check_map(char *line, t_data *data, int count_line);
int	set_map(char *line, t_data *data, int count_line);

#endif