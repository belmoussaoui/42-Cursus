/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:33:31 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/05 08:22:25 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "cub3d.h"

# define K_PRESS_EVENT 2
# define K_RELEASE_EVENT 3
# define DESTROY_NOTIFY_EVENT 17

# define NO_EVENT_MASK 0
# define K_PRESS_MASK 2
# define K_RELEASE_MASK 3

# ifdef LINUX
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_ESC 65307
#  define K_LEFT 65361
#  define K_RIGHT 65363

# else
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_ESC 53
#  define K_LEFT 123
#  define K_RIGHT 124
# endif

/* event */
int	quit(t_game *game);
int	key_down(int code, t_game *game);
int	key_release(int code, t_game *game);

#endif
