/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:18 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/21 15:18:39 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOKS_H
# define FDF_HOOKS_H

# define ESCAPE_BUTTON 53
# define MOUSE_LEFT_CLICK 1
# define DESTROY 17

void	ft_mlx_hooks(t_display *display);
int		ft_close_window(int keycode, t_display *display);

#endif