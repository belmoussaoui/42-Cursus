/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:15:53 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/29 13:17:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

int	top_tile(int tile_id, int column);
int	left_tile(int tile_id, int column);
int	top_left_tile(int tile_id, int column);

#endif