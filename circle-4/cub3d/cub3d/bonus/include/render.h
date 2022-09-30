/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:19:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/08/17 15:46:30 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define TILEMAP_SIZE 12
# define UI_H 150
# define UI_COLOR1 0x2d6e6f
# define UI_COLOR2 0x173f3f
# define MMAP_COLOR1 0x0000A8
# define MMAP_COLOR2 0x7CE7D6

# include "cub3d.h"

enum e_side
{
	N,
	E,
	S,
	W
};

typedef struct s_scanline
{
	t_vector	step;
	t_vector	floor;
}	t_scanline;

typedef struct s_ray
{
	double		dist;
	t_vector	dir;
	int			cell;
	enum e_side	side;
}	t_ray;

typedef struct s_draw_line_var
{
	int				tx;
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_img			*tex;
	t_ray			*ray;
	unsigned int	mask;
}	t_draw_line_var;

typedef struct s_th_arg
{
	int		i;
	void	*data[3];
}	t_th_arg;

/* dda */
void	dda(t_ray *ray, t_game *game);

/* floorcasting */
void	floorcasting(int y0, int y1, t_img *img, t_game *game);

/* hud */
void	render_ui(t_img *img, t_game *game);

/* minimap */
void	render_minimap(t_img *img, t_game *game);

/* raycasting */
void	raycasting(int x0, int x1, t_img *img, t_game *game);

/* render */
void	render(t_game *game);
void	load_floor_texture(t_game *game);

/* routines */
void	*routine_floor(void *arg);
void	*routine_sky(void *arg);
void	*routine_wall(void *arg);
void	*routine_rescale(void *arg);

/* skycasting */
void	load_sky_texture(t_game *game);
void	skycasting(int x0, int x1, t_img *img, t_game *g);

#endif
