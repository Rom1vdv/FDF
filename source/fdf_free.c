/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:31:26 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/24 19:43:49 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_split(char **split_line)
{
	int	j;

	j = 0;
	while (split_line[j])
	{
		free(split_line[j]);
		j++;
	}
	free(split_line);
}
