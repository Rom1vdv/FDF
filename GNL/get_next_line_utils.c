/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:57:31 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/24 18:00:18 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat_str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	cat_str = malloc(sizeof(*cat_str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat_str)
		exit(1);
	ft_strlcpy(cat_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(cat_str, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	free(s1);
	return (cat_str);
}
