/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:54:04 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 13:55:48 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *e)
{
	dputstr(STDERR_FILENO, "Error\n");
	dputstr(STDERR_FILENO, e);
	dputstr(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}
