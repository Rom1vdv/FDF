/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftesting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:32:36 by romvan-d          #+#    #+#             */
/*   Updated: 2022/05/05 15:16:30 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_put_pixel(t_image_data *data, int x, int y, int color)
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
    int x = 300;
    int y = 300;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.address= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (x <= 900)
    {
        my_mlx_put_pixel(&img, x, y, 0xFFFFFFFF);
        x++;
        y++;
    }
    x = 900;
    y = 900;
    while (y != 300)
    {
        my_mlx_put_pixel(&img, x, y, 0x000000FF);
        y--;
        x++;
    }
    x = 300;
    y = 300;
    while (x <= 1500)
    {
        my_mlx_put_pixel(&img, x, y, 0x000000FF);
        x++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // (0,0) est centre en haut a gauche de l'ecran si je ne me trompe pas.
    mlx_loop(mlx);
}

/*
struct->machin
=
(*struct).machin
*/

/* TO DO LIST
Changer le path dans le makefile de la dynamic libary
Changer GNL pour quil gere avec errno pour eviter de return NULL plusieurs fois
*/