/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:00:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/20 15:37:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_game {
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;
}	t_game;

t_game	setup();

void	push(t_list **out, t_list **in);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

void	print_game(t_game game);
void	test_instructions(t_game game);

#endif