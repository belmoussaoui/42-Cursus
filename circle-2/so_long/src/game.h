/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:27:52 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/15 16:51:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define FPS 60
# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 32
# define TITLE "so_long"

typedef struct s_map {
	char 	**data;
	int		width;
	int 	height;
	int 	collectibles;
	int 	players;
	int 	exits;
	int		display_x;
	int 	display_y;
	int		start_x;
	int		start_y;
}	t_map;

typedef struct	s_image {
	void	*texture;
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

typedef struct	s_player {
	t_sprite	sprite;
	t_sprite	spriteset;
	int			moves;
	int			direction;
} t_player;

typedef struct render {
	void	*mlx;
	void	*window;
	int		frames;
	int 	accumulator;
}	t_render;

typedef struct	s_game
 {
	t_render	render;
	t_player	player;
	t_sprite	empty;
	t_sprite	wall;
	t_sprite	exit;
	t_map		map;
	t_sprite	collectible;
}	 t_game;

int		game_loop(t_game *game);
void	play(t_game *game);
int		handle_input(int key, t_game *game);
void	load_texture(t_render *render, char *filepath, t_sprite *sprite);
void	game_update(t_game *game);
void	game_draw(t_game *game);
void	initialize_player(t_render *render, t_player *player, int x, int y);
void	initialize_map(t_map *player);
void	load_assets(t_game *game);
void	create_sprite(t_render *render, t_sprite *sprite, int w, int h);
void	create_image(t_render *render, t_image *image, int w, int h);
void	draw_player(t_render *render, t_player *player, t_map *map);
void	draw_sprite(t_render *render, t_image *src, t_image *dst, int sx, int sy);
void 	initialize(t_game *game);

#endif