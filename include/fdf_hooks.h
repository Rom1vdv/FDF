/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:18 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/04 18:19:57 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOKS_H
# define FDF_HOOKS_H

void	ft_mlx_hooks(t_display *display);
int 	ft_close_window(int keycode, t_display *display);

#endif