/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:12:50 by lrondia           #+#    #+#             */
/*   Updated: 2021/12/01 19:34:29 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_manager.h"
#include "process.h"
#include "file.h"

void	run_with_files(int argc, char **argv);
void	run_with_stdin(void);

int	main(int argc, char **argv)
{
	if (argc > 1)
		run_with_files(argc, argv);
	else
		run_with_stdin();
	return (0);
}

void	run_with_files(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 1;
	while (i < argc)
	{
		data = load_file(argv[i]);
		if (data.state == 0)
			write(2, "map error\n", 10);
		else
		{
			process(data);
			free(data.data);
		}
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

void	run_with_stdin(void)
{
	t_data	data;

	data = load_input();
	if (data.state == 0)
		write(2, "map error\n", 10);
	else
	{
		process(data);
		free(data.data);
	}
}
