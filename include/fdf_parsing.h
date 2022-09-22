/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:32:59 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/22 18:49:39 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSING_H
# define FDF_PARSING_H

#include "libft.h"
#include "get_next_line.h"

typedef struct s_fdf_map
{
    int **parsed_map;
    size_t  row_len;
    size_t  column_len;
}   t_fdf_map;

int		ft_check_file_extension(char *map_file);
t_list	*ft_convert_map_to_list(int map_fd);
int		*ft_parse_line(t_list *parsing_list);
t_fdf_map   ft_create_parsed_map(t_list *parsing_list);


#endif 