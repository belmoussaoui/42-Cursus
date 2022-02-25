/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/25 17:26:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>


typedef struct s_game {
	t_list	*stack_a;
	t_list	*stack_b;
	int 	head;
	int		n;
	int		*numbers;
}	t_game;

typedef struct s_action {
	int	index_a;
	int	index_b;
}	t_action;

void 	lock_sort(t_game *game);

t_game	setup_game(int argc, char **argv);

void	push(t_list **out, t_list **in);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

void	print_game(t_game game);
void	test_instructions(t_game game);

void	command_pa(t_game *game);
void	command_pb(t_game *game);

void	command_rra(t_game *game);
void	command_rrb(t_game *game);
void	command_rrr(t_game *game);

void	command_ra(t_game *game);
void	command_rb(t_game *game);
void	command_rr(t_game *game);

void	command_sa(t_game *game);
void	command_sb(t_game *game);
void	command_ss(t_game *game);


#endif