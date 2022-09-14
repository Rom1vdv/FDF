/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:12:30 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/13 20:31:04 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_draw_line(t_image_data *img, t_coordinates origin, t_coordinates end)
{
    t_coordinates delta;
    t_coordinates point;
    int decision_variable;
    
    delta.x = end.x - origin.x;
    delta.y = end.y - origin.y;
    decision_variable = 2 * delta.y - delta.x;
    point.x = origin.x;
    point.y = origin.y;
    my_mlx_put_pixel(img, point.x, point.y, WHITE);
    while (point.x < end.x)
    {
        point.x++;
        if (decision_variable < 0)
            decision_variable = decision_variable + 2 * delta.y;
        else
            {
                point.y++;
                decision_variable = decision_variable + 2 * (delta.y - delta.x);
            }
        my_mlx_put_pixel(img, point.x, point.y, WHITE);
    }
    
}

void my_mlx_put_pixel(t_image_data *data, int x, int y,int color)
{
    char  *dst;
	
    dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8)); // va a la position (x,y). // va a ladresse X + offset
    *(unsigned int *)dst = color; // met un pixel de couleur a cet endroit là. cast en unsigned int pour debloquer 4 bytes de memoires
}

int main(void)
{
	
    void *mlx;
    void *mlx_win;
    t_image_data img;
    int x = 0;
    int y = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.address= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_draw_line(&img,(t_coordinates) {1919,0},(t_coordinates) {1919,1079});
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // (0,0) est centre en haut a gauche de l'ecran si je ne me trompe pas.
    mlx_loop(mlx);
}