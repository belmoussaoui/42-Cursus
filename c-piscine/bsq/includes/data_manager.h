/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:22:12 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/01 07:52:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_MANAGER_H
# define DATA_MANAGER_H

# include <stdlib.h>
# include <fcntl.h>
# include "file.h"

typedef struct s_data
{
	int		lines;
	int		columns;
	char	symbols[3];
	int		*data;
	int		state;
}	t_data;

t_data	load_file(char *file);
t_data	load_input(void);
int		read_map(int fd, t_data *data);
int		read_input(char *line, t_data *data);

#endif