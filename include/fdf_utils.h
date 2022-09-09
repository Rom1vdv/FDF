/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:43:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/07 14:44:18 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

#include <stddef.h>

size_t	ft_strlen(const char *string);
char	*ft_strrchr(const char *string, int c);
int	ft_strarray_len(char **array);
void 	*my_malloc(size_t size);

#endif