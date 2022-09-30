/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:33:31 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/27 16:55:17 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "cub3d.h"

# define K_PRESS_EVENT 2
# define K_RELEASE_EVENT 3
# define MOUSE_MOVE 6
# define DESTROY_NOTIFY_EVENT 17

# define NO_EVENT_MASK 0
# define K_PRESS_MASK 2
# define K_RELEASE_MASK 3

# ifdef LINUX
#  define MAC 0
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_ESC 65307
#  define K_RIGHT 65363
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_UP 65362
#  define K_E 101
#  define K_CTRL 65507
#  define K_SPACE 32
#  define K_ENTER 65293

# else
#  define LINUX 0
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_ESC 53
#  define K_RIGHT 124
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_UP 126
#  define K_E 14
#  define K_CTRL 256
#  define K_SPACE 49
#  define K_ENTER 36
# endif

/* event */
int	key_down(int code, t_game *game);
int	key_release(int code, t_game *game);
int	mouse_hook(int x, int y, t_game *game);

/* quit */
int	quit(t_game *game);

#endif
