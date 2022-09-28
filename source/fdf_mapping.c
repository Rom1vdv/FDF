/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:44:54 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/28 18:39:40 by romvan-d         ###   ########.fr       */
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
            ft_draw_line(img, (t_coordinates){(row * 50) + 200, column * 50}, (t_coordinates){(row * 50) + 200, (column + 1 )* 50});
			ft_draw_line(img, (t_coordinates){(row * 50) + 200, column * 50}, (t_coordinates){((row + 1) * 50) + 200, column * 50});
            row++;
        }
        column++;
    }                
}