/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:50:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/10 18:53:02 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_link_map_points(t_image_data *img, t_fdf_map *map)
{

	t_coordinates matrix;
	t_coordinates res;
	
	matrix.y = 0;
	//printf("%zu-%zu\n", map->column_len, map->row_len);
	while (matrix.y < map->column_len)
	{
		matrix.x = 0;
		while (matrix.x < map->row_len)
		{
			// res = ft_isometric(&matrix, map); // dams cette merde deplacer le pt et puis ajuster au ratio et renvoyer les bonnes valeurs lol 
			res = matrix;
			printf("%d\n", res.x);
			if (matrix.y < map->column_len - 1)
				ft_draw_line(img, ft_ratio(res.x, res.y, map), ft_ratio(res.x, res.y + 1, map));
			if (matrix.x < map->row_len - 1)
				ft_draw_line(img, ft_ratio(res.x, res.y, map), ft_ratio(res.x + 1, res.y, map));
			matrix.x++; 
		}
		matrix.y++;
	}
}
