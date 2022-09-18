/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:36:25 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/18 21:27:55 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"

size_t	ft_strlen(char *string)
{
	size_t	i;
    
	i = 0;
    if (!string)
        return (0);
	while (string[i])
		  i++;
	return (i);
}

char	*ft_strrchr(const char *string, int target)
{
	char	*str;
	int		len_str;

	str = (char *)string;
	len_str = ft_strlen(str);
    if (!string)
        return (NULL);
	while (len_str >= 0)
	{
		if (str[len_str] == (char) target)
			return (&str[len_str]);
		len_str--;
	}
	return (0);
}

int	ft_strarray_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void *my_malloc(size_t size)
{
	void *tmp;

	tmp = malloc(size);
	
	if (tmp == NULL)
	{
		exit(1);
	}
	return (tmp);
}