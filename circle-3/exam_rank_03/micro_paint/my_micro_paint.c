/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:25:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/27 20:24:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background_char;
	char	*draw;
} 	t_zone;

typedef struct s_operation
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	character;
} t_operation;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	write_error(char *message)
{
	write(1, message, ft_strlen(message));
	return (1);
}

int	check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	i;

	i = 0;
	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background_char) != 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	zone->draw = malloc(sizeof(char) * zone->width * zone->height);
	while (i < zone->width * zone->height)
	{
		zone->draw[i] = zone->background_char;
		i++;
	}
	return (1);
}

int check_operation(t_operation *op)
{
    return (op->height > 0.0 && op->width > 0.0 && (op->type == 'r' || op->type == 'R'));
}

void	run_operation(t_operation *op, t_zone *zone)
{
    int i;
	int x;
	int y;
    int check = 1.0;

	i = 0;
    while (i < zone->height * zone->width)
    {
		x = i % zone->width;
		y = i / zone->width;
		if ((x < op->x) || (op->x + op->width < x) || (y < op->y) || (op->y + op->height < y))
		{
			i++;
			continue;
		}
        if (op->character == 'r')
		{
			if (((x - op->x) < check) || ((op->x + op->width) - x < check) || ((y - op->y) < check) || ((op->y + op->height) - y < check))
			{
				zone->draw[i] = op->character;
			}
		}
		else {
			zone->draw[i] = op->character;
		}
		i++;
    }
}

int	draw_operations(FILE *file, t_zone *zone)
{
	t_operation	op;
	int			input;

	while ((input = fscanf(file, "%c %f %f %f %f %c\n", &op.type, &op.x, &op.y, &op.width, &op.height, &op.character)) == 6)
	{
		if (!(check_operation(&op)))
			return (0);
		run_operation(&op, zone);
	}
    if (input != EOF)
        return (0);
	return (1);
}

void print_draw(t_zone *zone)
{
	int i = 0;

	while (i < zone->height)
	{
		write(1, zone->draw + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	FILE *file;
	t_zone zone;

	if (argc != 2)
		return (write_error("Error: argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (write_error("Error: Operation file corrupted\n"));
	if (!get_zone(file, &zone))
		return (write_error("Error: Operation file corrupted\n"));
	if (!(draw_operations(file, &zone)))
		return (write_error("Error: Operation file corrupted\n"));
	print_draw(&zone);
	return (0);
}
