/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:51:03 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/24 19:36:01 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinates	ft_ratio(int x, int y, t_fdf_map *map)
{
	t_coordinates	new_coord;
	int				ratio;

	ratio = 1000 / (map->column_len + map->row_len);
	new_coord.x = (x * ratio) + 510;
	new_coord.y = (y * ratio) + 610;
	new_coord = ft_isometric(x, y, &new_coord, map);
	return (new_coord);
}

t_coordinates	ft_isometric(int x, int y, t_coordinates *coordinates,
			t_fdf_map *map)
{
	t_coordinates	transformed_coord;

	transformed_coord.y = (coordinates->x - map->parsed_map[x][y]) / sqrt(2);
	transformed_coord.x = ((coordinates->x + 2 * coordinates->y
				+ map->parsed_map[x][y]) / sqrt(6));
	return (transformed_coord);
}
