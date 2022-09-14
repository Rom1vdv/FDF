/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:42:19 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/13 20:31:15 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include <stdio.h>
// /*

// la pente de la droite doit [si jai bien compris] etre positive parce que l'origine des points se trouvent en haut a gauche de la fenetre
// */


// void	ft_draw_line_low(t_image_data *img, t_coordinates origin,
// 				t_coordinates end)
// {
// 	int 			y_sign;
// 	int				d;
// 	t_coordinates	point;
// 	t_coordinates	delta;
	
// 	delta.x = end.x - origin.x;
// 	delta.y = end.y - origin.y;
// 	y_sign = 1;
// 	if (delta.y < 0)
// 	{
// 		y_sign = -1;
// 		delta.y = -delta.y;
// 	}
// 	d = (2 * delta.y) - delta.x;
// 	point.y = origin.y;
// 	point.x = origin.x;
// 	while (point.x <= end.x)
// 	{
// 		my_mlx_put_pixel(img, point.x, point.y, 0x000000FF);
// 		if (d > 0)
// 		{
// 			point.y = point.y + y_sign;
// 			d = d + (2 * (delta.y - delta.x));
// 		}
// 		else
// 			d = d + 2 * delta.y;
// 		point.x++;
// 	}	
// }

// void	ft_draw_line_high(t_image_data *img, t_coordinates origin,
// 				t_coordinates end)
// {
// 	int				x_sign;
// 	int				d;
// 	t_coordinates	delta;
// 	t_coordinates	point;
	
// 	delta.x = end.x - origin.x;
// 	delta.y = end.y - origin.y;
// 	x_sign = 1;
// 	if (delta.x < 0)
// 	{
// 		x_sign = -1;
// 		delta.x = -delta.x;
// 	}
// 	d = (2 * delta.x) - delta.y;
// 	point.y = origin.y;
// 	point.x = origin.x;
// 	while (point.y <= end.y)
// 	{
// 		my_mlx_put_pixel(img, point.x, point.y, 0x000000FF);
// 		if (d > 0)
// 		{
// 			point.x = point.x + x_sign;
// 			d = d + (2 * (delta.x - delta.y));
// 		}
// 		else
// 			d = d + 2 * delta.x;
// 		point.y++;
// 	}
// }

// void	ft_draw_line(t_image_data *img, t_coordinates origin, t_coordinates end)
// {
// 	int	abs_y;
// 	int	abs_x;

// 	abs_y = abs(end.y - origin.y);
// 	abs_x = abs(end.x - origin.x);
// 	if (abs_y < abs_x)
// 	{
// 		if (origin.x > end.x)
// 			ft_draw_line_low(img, end, origin);
// 		else
// 			ft_draw_line_low(img, origin, end);
// 	}
// 	else
// 	{
// 		if (origin.y > end.y)
// 			ft_draw_line_high(img, end, origin);
// 		else
// 			ft_draw_line_high(img, origin, end);	
// 	}
// }

// void my_mlx_put_pixel(t_image_data *data, int x, int y,int color)
// {
//     char  *dst;
	
//     dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8)); // va a la position (x,y). // va a ladresse X + offset
//     *(unsigned int *)dst = color; // met un pixel de couleur a cet endroit là. cast en unsigned int pour debloquer 4 bytes de memoires
// }

// int main(void)
// {
	
//     void *mlx;
//     void *mlx_win;
//     t_image_data img;
//     int x = 0;
//     int y = 0;
//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.address= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	ft_draw_line(&img,(t_coordinates) {1919,0},(t_coordinates) {1919,1079});
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // (0,0) est centre en haut a gauche de l'ecran si je ne me trompe pas.
//     mlx_loop(mlx);
// }