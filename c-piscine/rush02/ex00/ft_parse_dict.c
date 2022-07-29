/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:17:47 by dcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 14:40:27 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int ft_malloc_dict(t_data *data, int nb_suffix)
{
    data->dict = (char **)malloc(sizeof(char *) * (data->dict_size - nb_suffix) + 1);
    if (!data->dict)
        return (0);
    data->dict_key = (int *)malloc(sizeof(int) * (data->dict_size - nb_suffix));
    if (!data->dict_key)
        return (0);
    data->suffix = (char **)malloc(sizeof(char *) * (nb_suffix) + 1);
    if (!data->suffix)
        return (0);
    data->suffix_key = (int *)malloc(sizeof(int) * (nb_suffix));
    if (!data->suffix_key)
        return (0);
}

int ft_parse_suffixe(t_data *data, char *str)
{
    

}

int ft_parse_number(t_data *data, char *str, int index)
{
    int i;

    i = 0;
    data->dict_key[index] = ft_atoi(str);
    while (str[i] != ':')
        i++;
    i++;
    while (str[i] == ' ')
        i++;
    data->dict_key[index] = (char *)malloc((sizeof(char) * ft_strlen_new_line + 1);
    if (!data->dict_key[index])
        return (0);
    ft_strcpy_line(data->dict_key[index], &str[i]);
    return (1);
}

int ft_parse_dict(t_data *data)
{
    int i;
    int nb_suffix;

    i = 0;
    nb_suffix = 0;
    while (data->file_str[i])
    {
        if (ft_is_suffix(&data->file_str[i]) == 1)
            nb_suffix++:
        while (data->file_str[i] != '\n' && data->file_str[i])
            i++;
        if (data->file_str[i] == '\n')
            i++;
    }
    if (ft_malloc_dict(game, nb_suffix) == 0)
        return (0);
    i = 0;
    while (data->file_str[i])
    {
        if (ft_is_suffix(&data->file_str[i]) == 1)
        {

        }
        else
        {

        }
        while (data->file_str[i] != '\n' && data->file_str[i])
            i++;
    }
}