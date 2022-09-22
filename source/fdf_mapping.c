/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:44:54 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/22 18:54:46 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    link_map_points(t_image_data *img, t_fdf_map *map)
{
    int row;
    int column;

    
    column = 0;
    while(column < map->column_len)
    {
        row = 0;
        while(row < map->row_len)
        {
              ft_draw_line(img, (t_coordinates){*parsing_map[row], *parsing_map[column]}, (t_coordinates){*parsing_map[row + 1], *parsing_map[column + 1]});
              row++;
        }
        column++;
    }
}