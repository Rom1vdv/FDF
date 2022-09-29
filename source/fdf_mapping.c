/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:50:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/29 15:14:50 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    link_map_points(t_image_data *img, t_fdf_map *map)
{
    size_t row;
    size_t column;
	
    column = 0;
	printf("%zu-%zu\n", map->column_len, map->row_len);
    while(column < map->column_len)
    {
        row = 0;
        while(row < map->row_len)
        {	
			if (column < map->column_len - 1)
            	ft_draw_line(img, (t_coordinates){(row * 50) + 800, (column * 50) + 350}, (t_coordinates){(row * 50) + 800, ((column + 1)* 50) + 350});
			if (row < map->column_len - 1)
				ft_draw_line(img, (t_coordinates){(row * 50) + 800, (column * 50) + 350}, (t_coordinates){((row + 1) * 50) + 800, (column * 50) + 350});
            row++;
        }
        column++;
    }                
}
