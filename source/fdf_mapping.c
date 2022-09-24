/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:44:54 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/24 19:04:36 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    link_map_points(t_image_data *img, t_fdf_map *map)
{
    size_t row;
    size_t column;

    
    column = 0;
    while(column < map->column_len)
    {
        row = 0;
        while(row < map->row_len)
        {
              ft_draw_line(img, (t_coordinates){*map->parsed_map[row], *map->parsed_map[column]}, (t_coordinates){*map->parsed_map[row + 1], *map->parsed_map[column + 1]});
              row++;
        }
        column++;
    }
}