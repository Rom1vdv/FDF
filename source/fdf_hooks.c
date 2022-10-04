/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:05 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/04 17:59:45 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_close_window(int keycode, t_display *display)
{
	mlx_destroy_window(display->mlx, display->window);
	return (0);
}

void	ft_mlx_hooks(t_display *display)
{
	mlx_hook(display->window, 2, 1L<<0, ft_close_window, &display);
}