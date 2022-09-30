/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:54:02 by bperraud          #+#    #+#             */
/*   Updated: 2022/09/30 10:33:01 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_sound(char *path, t_game *g)
{
	char	*str;

	if (!fork())
	{
		str = strjoin("afplay sounds/", path);
		system(str);
		free(str);
		quit(g);
	}
}
