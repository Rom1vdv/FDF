/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:05 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/24 19:39:48 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(int keycode, t_display *display)
{
	if (keycode == ESCAPE_BUTTON)
	{
		mlx_destroy_image(display->mlx, display->img.img);
		mlx_destroy_window(display->mlx, display->window);
		exit(1);
	}
	return (0);
}

int	ft_close_window_cross(t_display *display)
{
	(void) display;
	exit(1);
}

void	ft_mlx_hooks(t_display *display)
{
	mlx_key_hook(display->window, ft_close_window, display);
	mlx_hook(display->window, DESTROY, 0, ft_close_window_cross, display);
}
