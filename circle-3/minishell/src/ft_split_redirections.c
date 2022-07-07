/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:21:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 12:20:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_split(t_data *data, char const *s)
{
	int	i;
	int	count;
	int	trigger;

	i = 0;
	count = 0;
	trigger = 1;
	while (s[i])
	{
		if (trigger && s[i] != '<' && s[i] != '>')
		{
			count++;
			trigger = 0;
		}
		if (!check_quote(data, s[i])
			&& (s[i] == '<' || s[i] == '>') && s[i + 1] != s[i])
		{
			count++;
			trigger = 1;
		}
		i++;
	}
	clear_quote(data);
	return (count);
}

int	count_char(t_data *data, char *s)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (s[i] == '<' || s[i] == '>')
	{
		while (s[i] == '<' || s[i] == '>')
			i++;
	}
	else
	{
		while (s[i] && ((s[i] != '<' && s[i] != '>') || check == 1))
		{
			check = check_quote(data, s[i]);
			i++;
		}	
	}
	clear_quote(data);
	return (i);
}

void	copy_str(t_data *data, char **s, char **res, int count)
{
	int	i;
	int	j;
	int	current;
	int	count_ch;

	j = 0;
	current = 0;
	while (current < count)
	{
		i = 0;
		while (s[j][i])
		{
			count_ch = count_char(data, s[j] + i);
			res[current] = malloc(sizeof(char) * (count_ch + 1));
			if (!res[current])
				free_split(res);
			ft_strlcpy(res[current], s[j] + i, count_ch + 1);
			i += count_ch;
			current++;
		}
		j++;
	}
}

char	**ft_split_redirections(t_data *data, char **s)
{
	int		i;
	int		count;
	char	**res;

	i = 0;
	count = 0;
	if (!s)
		exit (EXIT_FAILURE);
	while (s[i])
	{
		count += count_split(data, s[i]);
		i++;
	}
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		exit(EXIT_FAILURE);
	copy_str(data, s, res, count);
	res[count] = NULL;
	free_split(s);
	return (res);
}
