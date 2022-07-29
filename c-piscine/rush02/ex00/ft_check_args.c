/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:01:04 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/28 14:43:28 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_unsigned_integer(char *number)
{
	int	len;

	len = ft_strlen(number);
	if (!ft_is_numeric(number))
		return (0);
	if (len > 10 || (len == 10 && ft_strcmp(number, "4294967295") > 0))
		return (0);
	return (1);
}

int	ft_is_valid_args(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
		return (ft_is_unsigned_integer(argv[1]));
	fd = ft_open_file(argv[1]);
	if (fd == 0)
		return (0);
	close(fd);
	if (!ft_is_unsigned_integer(argv[2]))
		return (0);
	return (1);
}
