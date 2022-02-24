/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/24 18:42:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
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

t_game	setup_game(int argc, char **argv);

void	push(t_list **out, t_list **in);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

void	print_game(t_game game);
void	test_instructions(t_game game);

#endif