/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:27:52 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/22 16:07:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define FPS 60
# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 32
# define TITLE "so_long"

typedef struct s_sprite {
	void	*image;
	char	*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_map {
	char		**data;
	t_sprite	tilemap;
	int			width;
	int			height;
	char		*name;
	int			collectibles;
	int			players;
	int			exits;
	int			x;
	int			y;
}	t_map;

typedef struct s_player {
	t_sprite	sprite;
	int			anim_count;
	int			move_count;
	int			direction;
}	t_player;

typedef struct s_enemy {
	t_sprite	sprite;
	int			anim_count;
	int			move_count;
	int			direction;
}	t_enemy;

typedef struct render {
	void	*mlx;
	void	*window;
	int		frames;
	int		accumulator;
}	t_render;

typedef struct s_backstage {
	t_sprite	empty;
	t_sprite	wall1;
	t_sprite	wall2;
	t_sprite	exit1;
	t_sprite	exit2;
	t_sprite	collectible;
	t_sprite	player_move;
	t_sprite	player_idle;
	t_sprite	enemy;
}	t_backstage;

typedef struct s_game
{
	t_render	render;
	t_player	player;
	t_enemy		enemy;
	t_backstage	backstage;
	t_map		map;
}	t_game;

void	free_game(t_game *game);
int		exit_game(t_game *game);
void	run(t_game *game);
void	initialize_render(t_render *render);
int		check_is_valid(t_map *map);
int		error_message(char *message);
void	free_map(t_render *render, t_map *map);
int		game_loop(t_game *game);
void	play(t_game *game);
int		handle_input(int key, t_game *game);
void	load_xpm_file(t_render *render, char *filepath, t_sprite *sprite);
void	game_update(t_game *game);
void	game_draw(t_game *game);
void	initialize_render(t_render *render);
void	initialize_player(t_render *render, t_player *player);
void	initialize_map(t_game *game, t_render *render, t_map *player);
void	load_assets(t_game *game);
void	create_sprite(t_render *render, t_sprite *sprite, int w, int h);
void	create_image(t_render *render, t_sprite *image, int w, int h);
void	draw_map(t_render *render, t_map *map);
void	draw_player(t_render *render, t_backstage *backstage, t_player *player);
void	set_starting_position(t_player *player, t_map *map);
void	blt_dst(t_sprite *src, t_sprite *dst, int dx, int dy);
void	blt_src(t_sprite *src, t_sprite *dst, int sx, int sy);
void	initialize(t_game *game);
void	update_map(t_map *map, t_player *player);
void	update_player(t_player *player);
void	update_move(t_game *game, t_player *player, int direction);
void	clear_sprite(t_sprite *sprite);
void	draw_tilemap(t_backstage *backstage, t_map *map);
void	draw_enemy(t_render *render, t_backstage *backstage, t_enemy *enemy, t_map *map);
void	set_starting_position_enemy(t_enemy *enemy, t_map *map);
void	update_enemy(t_enemy *enemy, t_player *player, t_map *map);

#endif