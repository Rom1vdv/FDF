/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:46:23 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/25 15:28:44 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_tab_parsing(char **argv, int fd, t_fdf_map *map,
		t_list *parsing_list)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	parsing_list = ft_convert_map_to_list(fd);
	*map = ft_create_parsed_map(parsing_list);
	ft_lstclear(&parsing_list, &free);
}

void	ft_init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		exit(1);
	display->window = mlx_new_window(display->mlx, 1920, 1080, "FDF");
	display->img.img = mlx_new_image(display->mlx, 1920, 1080);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_list			parsing_list;
	t_fdf_map		map;
	t_display		display;
	t_image_data	img;

	fd = 0;
	if (argc == 2)
	{
		if (ft_check_file_extension(argv[1]) == 1)
		{
			ft_init_tab_parsing(argv, fd, &map, &parsing_list);
			ft_init_mlx(&display, &img);
			ft_link_map_points(&img, &map);
			mlx_put_image_to_window(display.mlx, display.window,
				display.img.img, 0, 0);
			ft_mlx_hooks(&display);
			mlx_loop(display.mlx);
		}
	}
	return (1);
}
