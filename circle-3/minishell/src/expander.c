/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 03:28:19 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/30 16:35:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expands_error(t_list **new, char *element)
{
	char	*val_var;
	int		i;

	if (!element[0])
	{
		ft_lstadd_back(new, ft_lstnew(ft_strdup("$")));
		return (1);
	}
	val_var = ft_itoa(g_error_code);
	if (!val_var)
		exit(EXIT_FAILURE);
	i = 0;
	while (val_var[i])
	{
		ft_lstadd_back(new, ft_lstnew(val_var + i));
		i++;
	}
	return (i + 1);
}

int	expands_variable(t_data *data, t_list **new, char *element)
{
	int		len_var;
	char	*name_var;
	char	*val_var;
	int		i;

	len_var = 0;
	while (ft_isalnum(element[len_var]) || element[len_var] == '_')
		len_var++;
	if (len_var == 0 && (element[len_var] == '?' || !element[len_var]))
		return (expands_error(new, element));
	name_var = malloc(sizeof(char) * (len_var + 1));
	if (!name_var)
		exit(EXIT_FAILURE);
	ft_strlcpy(name_var, element, len_var + 1);
	val_var = get_env(data->new_env, name_var);
	if (!val_var)
		val_var = "";
	free(name_var);
	i = 0;
	while (val_var[i])
	{
		ft_lstadd_back(new, ft_lstnew(val_var + i));
		i++;
	}
	return (len_var + 1);
}

void	remplace_element(t_list *new, char **element)
{
	int		i;
	char	*copy;

	copy = *element;
	*element = malloc(sizeof(char) * ft_lstlen(new));
	if (!*element)
		exit(EXIT_FAILURE);
	i = 0;
	while (new)
	{
		(*element)[i] = ((char *)(new->content))[0];
		new = new->next;
		i++;
	}
	(*element)[i] = '\0';
	free(copy);
}

void	expands_element(t_data *data, char **element)
{
	int		i;
	char	*str;
	t_list	*new;

	i = 0;
	new = NULL;
	str = *element;
	while (str[i])
	{
		check_quote(data, str[i]);
		if (str[i] == '$' && data->s_quote == 0)
			i += expands_variable(data, &new, str + i + 1);
		else if ((str[i] != '"' || data->s_quote)
			&& (str[i] != '\'' || data->d_quote))
		{
			ft_lstadd_back(&new, ft_lstnew(str + i));
			i++;
		}
		else
			i++;
	}
	remplace_element(new, element);
	ft_lstclear(&new, NULL);
	clear_quote(data);
}

// Replace the variables with their values.
void	expander(t_data *data, t_list *commands)
{
	int		i;
	t_cmd	*content;

	while (commands)
	{
		content = (t_cmd *)(commands->content);
		i = 0;
		while (content->elements[i])
		{
			expands_element(data, content->elements + i);
			i++;
		}
		commands = commands->next;
	}
}
