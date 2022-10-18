/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:50:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/17 20:19:32 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_link_map_points(t_image_data *img, t_fdf_map *map)
{

	t_coordinates matrix;
	t_coordinates res;
	
	matrix.y = 0;

	while (matrix.y < map->column_len)
	{
		matrix.x = 0;
		while (matrix.x < map->row_len)
		{
			res = matrix;
			if (matrix.y < map->column_len - 1)
				ft_draw_line(img, ft_ratio(res.x, res.y, map), ft_ratio(res.x, res.y + 1, map));
			if (matrix.x < map->row_len - 1)
				ft_draw_line(img, ft_ratio(res.x, res.y, map), ft_ratio(res.x + 1, res.y, map));
			matrix.x++; 
		}
		matrix.y++;
	}
}
