/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:08:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/08/16 19:43:51 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_TITLE "cub3d"
# define SCREEN_W 1350
# define SCREEN_H 900
# define SCALE 0.8
# define N_THREAD 4
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define MRS 0.003 // Mouse rotation speed
# define PLANE_LENGTH 0.7
# define PI2_F 6.28318530718
# define RED 0x00FF0000
# define DEATH_SIZE 4

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <stdint.h>
# include <pthread.h>

# include "data_struct.h"
# include "scene.h"
# include "parsing.h"
# include "utils.h"
# include "gameloop.h"
# include "event.h"
# include "render.h"
# include "sprite.h"
# include "enemy.h"

#endif
