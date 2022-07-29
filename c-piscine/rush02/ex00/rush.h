/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:42:11 by llaruell          #+#    #+#             */
/*   Updated: 2021/11/28 21:18:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
#define RUSH_H

#define UNSIGNED_INT_MAX 4294967295

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_data
{
    int 	fd;
    int 	number_size;
    int 	dict_size;
    char 	*number;
    char 	**dict;
	int 	*dict_key; 
	char 	default_matrice[28][];
	int		default_key[28];
	char	default_suffix[13][];
	int 	default_key_suffixe[13];
	int 	*suffix_key;
	char 	**suffix;
    char 	dict_path;
    char 	*file_str;

} t_data;

/*
 *	ERROR
 */
void ft_destroy();
int ft_error();
void ft_error_dict();
int ft_open_file(char *dict);
int ft_strlen(char *str);
int ft_strcmp(char *number, char *u_i_max);
int ft_is_numeric(char *number);
int ft_is_valid_args(int argc, char **argv);
int ft_init(t_data *data, char **argv);
char *ft_join(char *s1, char *s2);
int	ft_char_is_printable(char c);
int ft_rules_lines(t_data *data);
int ft_is_suffix(char *str);
int ft_strlen_new_line(char *str);

/*
 * Parsing
 */

/*
 * Check
 */

/*
 * Print
 */

/*
 *	Process
 */

/*
 * Utils
 */
unsigned int ft_atoi(char *str);
#endif
