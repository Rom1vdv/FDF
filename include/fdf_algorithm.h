/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algorithm.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:18:38 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/24 18:18:06 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ALGORITHM_H
# define FDF_ALGORITHM_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "fdf_parsing.h"
# define WHITE 0x00FFFFFF

typedef struct s_image_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_data;

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

void    link_map_points(t_image_data *img, t_fdf_map *map);
void 	my_mlx_put_pixel(t_image_data *data, int x, int y, int color);
void	ft_draw_line(t_image_data *img, t_coordinates origin, t_coordinates end);

#endif