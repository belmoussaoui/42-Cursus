/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:32:21 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 18:11:46 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# define BUFFER_SIZE 2048

/* utils */
bool			atoui8_error(const char *s, uint8_t *n);
int				isdigit(int c);
int				isascii_48(int c);
int				shade_color(int color, double divide);
int				ft_atoi(const char *str);

/* sound */
void			play_sound(char *path, t_game *g);

/* color */
int				get_r(int c);
int				get_g(int c);
int				get_b(int c);
int				rgb(uint8_t r, uint8_t g, uint8_t b);
int				shade(int cf, int cb, double af, double ab);

/* copy */
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			str_n_cpy(char *dst, char *src, size_t len);

/* error */
void			exit_error(char *e);

/* find */
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*skip_spaces(char *s);

/* get_next_line */
char			*get_next_line(int fd);

/* get_next_non_empty_line */
char			*get_next_non_empty_line(int fd);
bool			is_empty_line(char *line);

/* min_max */
int64_t			min(int64_t a, int64_t b);
int64_t			max(int64_t a, int64_t b);

/* mlx_utils */
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_img			get_new_img(void *mlx, int width, int height);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
t_img			get_img_from_xpm(void *mlx, char *path);

/* put */
void			dputstr(int fd, char *s);

/* split */
char			**ft_split(char const *str, char c);

/* str */
size_t			str_len(const char *str);
char			*ft_strncpy(char *dest, const char *src, unsigned int n);
char			*strjoin(char const *s1, char const *s2);
int				str_n_cmp(const char *s1, const char *s2, size_t n);
bool			is_token(char *str, char *tokens, char sep, size_t n);

/* str_alloc */
char			*ft_strdup(const char *s);
char			*str_n_dup(char *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/* str_arr */
void			str_arr_free(char **str);
size_t			str_arr_len(char **str);

/* swap */
void			swap_int(int *a, int *b);

/* thread */
int				get_start(int i, int start, int end, int n_thread);
int				get_end(int i, int start, int end, int n_thread);

/* x_alloc */
void			*x_malloc(size_t n);
void			*x_calloc(size_t count, size_t size);

/* mac mouse functions */
int				mac_mouse_hide(void);
int				mac_mouse_move(int x, int y);
int				mlx_mouse_move(void *mlx, void *win, int x, int y);
int				mlx_mouse_get_pos(void *mlx, void *win, int *x, int *y);
int				mlx_mouse_hide(void *mlx, void *win);

void			blt_dst(t_img *src, t_img *dst, t_vector d, t_rect r);

#endif
