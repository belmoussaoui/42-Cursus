/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:51:26 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/10 19:24:07 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FPS 60

typedef struct s_map {
	char **data;
	int width;
	int height;
}	t_map;

typedef struct	s_image {
	void	*ptr;
	char	*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct	s_sprite {
	int		x;
	int		y;
	int		width;
	int		height;
	t_image	image;
} t_sprite;

typedef struct	s_game
 {
	void		*mlx;
	void		*window;
	float		accumulator;
	t_map		map;
	t_sprite	wall;
	t_sprite	mario;
	t_sprite	empty;
	int 		start_x;
	int 		start_y;
}	 t_game;

#endif