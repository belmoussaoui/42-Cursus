/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:55:50 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/02 20:24:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	while_is_charset(char *str, char *charset, int i)
{
	while (str[i] && is_charset(str[i], charset))
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = while_is_charset(str, charset, 0);
	count = 0;
	if (str[i])
		count++;
	while (str[i])
	{
		if (is_charset(str[i], charset))
		{
			count += 1;
			i = while_is_charset(str, charset, i);
		}
		else
			i++;
	}
	return (count);
}

void	set_word(char *res, char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		n_words;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	n_words = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			i = while_is_charset(str, charset, i);
		else
		{
			j = 0;
			while (str[i + j] && !is_charset(str[i + j], charset))
				j++;
			res[n_words] = malloc(sizeof(char) * (j + 1));
			set_word(res[n_words++], str + i, charset);
			i += j;
		}
	}
	res[n_words] = 0;
	return (res);
}
