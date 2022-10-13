/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:57:51 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/10 19:03:02 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORMATIONS_H
# define FDF_TRANSFORMATIONS_H

# include "fdf_parsing.h"
# include "fdf_algorithm.h"

t_coordinates	ft_isometric(int x, int y, t_coordinates *coordinates, t_fdf_map *map);
t_coordinates	ft_ratio(int x, int y, t_fdf_map *map);

#endif