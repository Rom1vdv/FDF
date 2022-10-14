/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:51:03 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/14 20:36:17 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinates	ft_ratio(int x, int y, t_fdf_map *map)
{
	t_coordinates	new_coord;
	int			ratio;
	
	// printf("in tab: %d %d\n", x, y);
	ratio = 500 / map->column_len;
	new_coord.x = (x * ratio) + 710;
	new_coord.y = (y * ratio) + 90;
	// printf("coords %d %d\n", new_coord.x, new_coord.y);
	new_coord = ft_isometric(x, y, &new_coord, map);
	return (new_coord);
}

t_coordinates	ft_isometric(int x, int y, t_coordinates *coordinates, t_fdf_map *map)
{
	t_coordinates	transformed_coord;
	
	// printf("coucou\n");
	transformed_coord.x = (coordinates->x - map->parsed_map[x][y]) / sqrt(2);
	transformed_coord.y = (coordinates->x + 2 * coordinates->y + map->parsed_map[x][y]) / sqrt(6);
	// printf("Coord X isometrique : %d\n", transformed_coord.x);
	// printf("Coord Y isometrique : %d\n", transformed_coord.y);
	return (transformed_coord);
}
