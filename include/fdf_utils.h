/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:43:01 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/25 21:04:10 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

#include <stddef.h>
#include <stdlib.h>


size_t	ft_strlen(char *string);
char	*ft_strrchr(const char *string, int c);
size_t	ft_strarray_len(char **array);
void 	*my_malloc(size_t size);

#endif