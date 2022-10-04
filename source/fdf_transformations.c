/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:51:03 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/04 16:23:23 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinates	ft_isometric(t_coordinates coordinates, t_fdf_map *map)
{
	t_coordinates	transformed_coord;

	
	transformed_coord.x = (sqrt(2) / 2) * (coordinates.x - coordinates.y);
	transformed_coord.y = sqrt(2 / 3)
		* map->parsed_map[coordinates.x][coordinates.y] - 1 / (sqrt(6))
		* (coordinates.x + coordinates.y);
	printf("Coord X isometrique : %d\n", transformed_coord.x);
	printf("Coord Y isometrique : %d\n", transformed_coord.y);
	return (transformed_coord);
}
