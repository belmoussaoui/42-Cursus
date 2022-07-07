/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:02:25 by hakermad          #+#    #+#             */
/*   Updated: 2022/06/29 22:15:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (-1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (src[i] && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

void	ft_strinsert(char **astr, char *str, size_t i, size_t n)
{
	char	*dst;

	if (!astr || !*astr || !str)
		return ;
	dst = malloc((ft_strlen(*astr) + ft_strlen(str) + 1) * sizeof(char));
	if (dst == NULL)
		exit(EXIT_FAILURE);
	ft_strncpy(dst, *astr, i);
	ft_strncpy(dst + i, str, n);
	ft_strncpy(dst + i + (ft_strlen(str), n), *astr + i, ft_strlen(*astr));
	free(*astr);
	*astr = dst;
}

static char	*get_path(t_data *data)
{
	char		*path;
	const char	*home = getenv("HOME");

	path = NULL;
	if (data->elements[1])
	{
		path = getcwd(NULL, 0);
		ft_strinsert(&path, "/", ft_strlen(path), 1);
		ft_strinsert(&path, data->elements[1], ft_strlen(path),
			ft_strlen(data->elements[1]));
	}
	else
		chdir(home);
	return (path);
}

bool	ft_cd(t_data *data)
{
	char	*path;

	if (get_pwd() == NULL)
		return (true);
	update_pwd(data, "OLDPWD=");
	path = get_path(data);
	if (!path)
		return (true);
	if (chdir(path) < 0)
	{
		perror(path);
		free(path);
		return (true);
	}
	update_pwd(data, "PWD=");
	free (path);
	return (false);
}
