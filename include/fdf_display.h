/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:54:44 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/21 15:18:25 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DISPLAY_H
# define FDF_DISPLAY_H

typedef struct s_display
{
	void			*mlx;
	void			*window;
	t_image_data	img;
}			t_display;

#endif