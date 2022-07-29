/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_rush.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:30:05 by lrondia           #+#    #+#             */
/*   Updated: 2021/11/21 18:40:13 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_RUSH_H
# define LIBRARY_RUSH_H

int		is_column_valid(char param, int tab[4][4], int col);
int		is_column_down_valid(char param, int tab[4][4], int col);
int		is_row_left(char param, int tab[4][4], int col);
int		is_row_right(char param, int tab[4][4], int col);
int		is_valid_solution_column(char *params, int tab[4][4]);
int		is_valid_solution_row(char *params, int tab[4][4]);
int		is_column_valid(char param, int tab[4][4], int col);
int		is_valid_next(int tab[4][4], int col, int row);
int		is_valid_arg(char *params);
void	next_position(int *next_row, int *next_col, int row, int col);

#endif
