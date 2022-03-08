/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 23:59:35 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_game {
	t_list	*stack_a;
	t_list	*stack_b;
	int		head;
	int		n;
	int		*numbers;
}	t_game;

typedef struct s_action {
	int	index_a;
	int	index_b;
}	t_action;

void		twin_sort(t_game *game);

void		lock_sort(t_game *game);

t_action	lock_action(t_game *game);

void		lock_rotate(t_game *game, t_action action);

void		free_game(t_game *game);
t_game		setup_game(int argc, char **argv);
void		exit_error(t_game *game);

char		**handle_one_arg(char *arg, t_game *game);
char		**handle_many_args(int argc, char **argv);
void		free_argv(t_game *game, char **argv, int exit);
int			check_number(char *nbr, t_game *game, char **argv);
void		check_duplicates(t_game *game, char **argv);

void		push(t_list **out, t_list **in);
void		swap(t_list **lst);
void		rotate(t_list **lst);
void		reverse_rotate(t_list **lst);

void		print_game(t_game game);
void		test_instructions(t_game game);

void		command_pa(t_game *game);
void		command_pb(t_game *game);

void		command_rra(t_game *game);
void		command_rrb(t_game *game);
void		command_rrr(t_game *game);

void		command_ra(t_game *game);
void		command_rb(t_game *game);
void		command_rr(t_game *game);

void		command_sa(t_game *game);
void		command_sb(t_game *game);
void		command_ss(t_game *game);

void		interpreter_push(t_game *game, char *command);
void		interpreter_swap(t_game *game, char *command);
void		interpreter_rotate(t_game *game, char *command);
void		interpreter_reverse(t_game *game, char *command);

#endif