/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:02:47 by lrondia           #+#    #+#             */
/*   Updated: 2021/12/01 13:47:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process(t_data data)
{
	int	*score;

	score = create_score(data);
	set_score(data, score);
	print_res(data);
	free(score);
}

int	*create_score(t_data data)
{
	int	*score;
	int	i;

	i = 0;
	score = malloc(sizeof(int) * data.lines * data.columns);
	while (i < (data.lines * data.columns))
	{
		if (data.data[i] == 1)
			score[i] = 0;
		else
			score[i] = 1;
		i++;
	}
	return (score);
}

void	set_score(t_data data, int *score)
{
	int	i;
	int	left;
	int	top;
	int	top_left;
	int	best_score_id;

	i = 0;
	best_score_id = 0;
	while (i < (data.lines * data.columns))
	{
		left = left_tile(i, data.columns);
		top = top_tile(i, data.columns);
		top_left = top_left_tile(i, data.columns);
		if (score[i] != 0 && left >= 0 && top >= 0 && top_left >= 0)
			score[i] = ft_min(score[left], score[top], score[top_left]) + 1;
		if (score[best_score_id] < score[i])
			best_score_id = i;
		i++;
	}
	if (score[best_score_id] > 0)
	{
		data.data[best_score_id] = 2;
		set_biggest_square(&data, score, best_score_id);
	}
}

void	set_biggest_square(t_data *data, int *score, int best)
{
	int	i;
	int	j;

	j = score[best];
	while (j > 1)
	{
		i = 0;
		while (i < j)
		{
			data->data[best - i] = 2;
			i++;
		}
		i = 0;
		while (i < j)
		{
			data->data[best - (data->columns * i)] = 2;
			i++;
		}
		best = top_left_tile(best, data->columns);
		j--;
	}
	data->data[best] = 2;
}

void	print_res(t_data data)
{
	int	i;

	i = 0;
	while (i < (data.lines * data.columns))
	{
		write(1, &data.symbols[data.data[i]], 1);
		i++;
		if (i % data.columns == 0)
			write(1, "\n", 1);
	}
}
