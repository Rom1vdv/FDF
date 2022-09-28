/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:46:23 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/28 11:36:03 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int main(int argc, char **argv)
{
    int     fd;
    t_list  *parsing_list;
    t_fdf_map map;
    void *mlx;
    void *mlx_win;
    t_image_data img;
    
    if (argc == 2)
    {
        if (ft_check_file_extension(argv[1]) == 1)
        {
            fd = open(argv[1], O_RDONLY);
            parsing_list = ft_convert_map_to_list(fd);
            map = ft_create_parsed_map(parsing_list);
            mlx = mlx_init();
            mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
            img.img = mlx_new_image(mlx, 1920, 1080);
            img.address= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
            link_map_points(&img, &map);
            mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
            mlx_loop(mlx);
            printf("This cell equals to : %d\n", map.parsed_map[11][11] );
            
        }
    }
    return (0);
}