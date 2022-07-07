/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:20 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/29 22:33:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static	int	count_split(t_data *data, char const *s)
{
	int	count;
	int	i;
	int	trigger;

	count = 0;
	trigger = 1;
	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && trigger)
		{
			count++;
			trigger = 0;
		}
		if (!check_quote(data, s[i]) && ft_isspace(s[i]) && !trigger)
			trigger = 1;
		i++;
	}
	clear_quote(data);
	return (count);
}

static	int	count_char(t_data *data, char const *s)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (s[i] && (!ft_isspace(s[i]) || check == 1))
	{
		check = check_quote(data, s[i]);
		i++;
	}
	clear_quote(data);
	return (i);
}

void	*free_split(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

char	**ft_split_quote(t_data *data, char const *s)
{
	int		i;
	char	**res;
	int		current;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_split(data, s) + 1));
	if (!res)
		exit (EXIT_FAILURE);
	i = 0;
	current = 0;
	while (current < count_split(data, s))
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		res[current] = malloc(sizeof(char) * (count_char(data, s + i) + 1));
		if (res[current] == NULL)
			return (free_split(res));
		ft_strlcpy(res[current], s + i, count_char(data, s + i) + 1);
		i += count_char(data, s + i);
		current++;
	}
	res[current] = NULL;
	return (res);
}
