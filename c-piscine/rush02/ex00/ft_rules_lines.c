/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:36:36 by dcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 13:20:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int ft_check_value(char *str, int i)
{
    while (str[i] && str[i] != '\n')
    {
        if (ft_char_is_printable(str[i]) == 0)
            return (0);
        i++;
    }
    return (i);
}


int ft_check_number(char *str, int i)
{
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
            || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            return (0);
        i++;
    }
    if (str[i] < '0' || str[i] > '9')
        return (0);
    while (str[i] && str[i] >= '0' && str[i] <= '9')
        i++;
    while (str[i] && str[i] != ' ' && str[i] != ':')
        i++;
    return (i);
}

int ft_rules_lines(t_data *data)
{
    int i;

    i = 0;
    while (data->file_str[i])
    {
        i = ft_check_number(data->file_str, i);
        if (i == 0)
            return (0);
        while (data->file_str[i] && data->file_str[i] == ' ')
            i++;
        if (data->file_str[i] != ':')
            return (0);
        i++;
        while (data->file_str[i] && data->file_str[i] == ' ')
            i++;
        i = ft_check_value(data->file_str, i);
        if (i == 0)
            return (0);
        if (data->file_str[i] && data->file_str[i] == '\n')
            i++;
    }
    return (1);
}