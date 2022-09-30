/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:28 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/29 23:19:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "cub3d.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef enum e_scene
{
	TITLE,
	GAME,
}	t_scene;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	void			*content;
}	t_node;

typedef struct s_list
{
	t_node	*head;
}	t_list;

typedef struct s_dy_str
{
	char	*str;
	size_t	alloc;
	size_t	len;
}	t_dy_str;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

/* circular_lst */
void		clst_add_back(t_list *lst, t_node *node);
void		clst_rotate(t_list *lst);
size_t		clst_size(t_list lst);
void		clst_clear(t_list *lst, void (*del)(void*));

/* dy_str_insert */
void		dy_str_append_str(t_dy_str *dy_str, char *s);

/* dy_str */
t_dy_str	dy_str_new(void);
void		dy_str_destroy(t_dy_str *dy_str);
void		dy_str_grow(t_dy_str *dy_str);
void		dy_str_append_c(t_dy_str *dy_str, char c);
void		dy_str_pop_back(t_dy_str *dy_str);

/* node */
t_node		*new_node(void *content);

/* circular lst */
void		lst_add_front(t_list *lst, t_node *new_node);
void		lst_clear(t_list *lst, void (*del)(void*));

/* vector */
t_vector	vector(double x, double y);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_scalar_multiplication(t_vector v, double a);
t_vector	vector_rotate(t_vector v, double a);
double		vector_norme(t_vector v);
double		vector_dot_product(t_vector v1, t_vector v2);
t_vector	vector_normalize(t_vector v);

#endif
