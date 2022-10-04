/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:50:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/04 18:22:02 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_link_map_points(t_image_data *img, t_fdf_map *map)
{

	t_coordinates matrix;
	
	matrix.y = 0;
	//printf("%zu-%zu\n", map->column_len, map->row_len);
	while (matrix.y < map->column_len)
	{
		matrix.x = 0;
		while (matrix.x < map->row_len)
		{
			ft_isometric(matrix, map);
			if (matrix.y < map->column_len - 1)
				ft_draw_line(img, (t_coordinates){(matrix.x * 50) + 800,
					(matrix.y * 50) + 350},
					(t_coordinates){(matrix.x * 50) + 800,
					((matrix.y + 1) * 50) + 350});
			if (matrix.x < map->row_len - 1)
				ft_draw_line(img, (t_coordinates){(matrix.x * 50) + 800,
					(matrix.y * 50) + 350},
					(t_coordinates){((matrix.x + 1) * 50) + 800,
					(matrix.y * 50) + 350});
			matrix.x++; 
		}
		matrix.y++;
	}
}
