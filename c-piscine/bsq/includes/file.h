/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 05:08:03 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/01 18:22:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <unistd.h>
# include "utils.h"

int	get_line(int fd, char **line);
int	get_input(char **line);
int	add_char(char **line, int *len, char **buffer, char *c);

#endif
