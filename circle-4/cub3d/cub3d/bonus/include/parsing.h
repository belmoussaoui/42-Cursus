/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:47:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 18:10:24 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define SPACES " \t"
# define WALL_MAX 79
# define SPRITE_MAX 20
# define GUN_MAX 4
# define ENEMY_MAX 10

typedef struct s_sprite	t_sprite;
typedef struct s_enemy	t_enemy;
typedef struct s_gun	t_gun;

typedef struct s_map
{
	int		*data;
	int		*object_map;
	bool	*visible_tiles;
	int		width;
	int		height;
	int		ceil;
	int		floor;
	int		ceil_repeat;
}	t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		fov;
}	t_player;

typedef struct s_door
{
	int		cell;
	bool	opened;
	double	ratio;
}	t_door;

typedef struct s_state
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	r_left;
	bool	r_right;
	int		m_left;
	int		m_right;
	bool	shoot;
}	t_state;

typedef struct s_texture
{
	t_img	*img;
	t_list	imgs;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			img_w;
	int			img_h;
	t_img		small_buffer;
	t_img		full_buffer;
	int			fps;
	int			active_gun;
	t_map		map;
	t_player	player;
	t_state		state;
	t_texture	walls[WALL_MAX];
	t_img		floor;
	t_img		sky;
	t_list		doors;
	t_enemy		*list_enemy[ENEMY_MAX];
	t_sprite	*list_sprite[SPRITE_MAX];
	t_gun		*list_gun[GUN_MAX];
	t_gun		*list_active_gun[2];
	double		depth_buf[SCREEN_W];
	t_scene		scene;
	t_title		title;
	bool		reflect;
	int			player_hp;
}	t_game;

/* check_map */
void		check_map(t_game *g);

/* get_map_str */
char		*get_map_str(int fd);

/* parse enemy */
void		parse_enemy(t_game *game, int fd);

/* parse_map */
void		parse_map(char *map_str, t_game *g);

/* parse_textures */
void		add_img(t_texture *texture, t_img img);
void		parse_textures(t_game *game, int fd);

/* parse_sprite */
void		bound_start(t_sprite *s, t_img text);
void		parse_sprite(t_game *game, int fd);

/* parse */
enum e_side	get_direction(char c);
void		parse(int argc, char **argv, t_game *game);

/* mlx mouse */
int			mouse_hide(t_game *game);
int			mouse_move(t_game *game, int x, int y);

/* linux mouse function */
void		my_mouse_hook(t_game *game);

#endif
