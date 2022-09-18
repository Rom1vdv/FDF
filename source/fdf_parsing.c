/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:17:40 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/18 21:43:16 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int	ft_check_file_extension(char *map_file)
{

	if(ft_strlen(map_file) > 4)
	{
		if (strcmp(map_file + ft_strlen(map_file) - 4, ".fdf") == 0)
			return (1);
	}
	return (0);
}

t_list	*ft_convert_map_to_list(int map_fd)
{
	char	*read_line;
	t_list	*parsing_list;
	t_list	*new_node;

	parsing_list = NULL;
	read_line = get_next_line(map_fd);
	while (read_line)
	{
		new_node = ft_lstnew_node(read_line);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&parsing_list, new_node);
		read_line = get_next_line(map_fd);
	}
	return (parsing_list);
}

/*Cette fonction split un node de la liste et ajoute chaque element dans une ligne dint */

int	*ft_parse_line(t_list *parsing_list)
{	
	char	**split_array;
	int		parsed_number;
	int		*parsed_line;
	int		i;

	i = 0;
	split_array = ft_split(parsing_list->content, ' ');
	parsed_line = my_malloc(sizeof(*parsed_line) * ft_strarray_len(split_array) + 1);
	while (split_array[i])
	{
		parsed_number = ft_atoi(split_array[i]);
		parsed_line[i] = parsed_number;
		i++;
	}
	return (parsed_line);
}

int	**ft_create_parsed_map(t_list *parsing_list)
{
	int	**parsed_map;
	int	i;
	int len_list;
	
	i = 0;
	len_list = ft_lstsize(parsing_list);
	parsed_map = my_malloc(sizeof(*parsed_map) * (len_list) + 1);
	while (i < len_list)
	{
		parsed_map[i] = ft_parse_line(parsing_list);
		i++;
		parsing_list = parsing_list->next;
	}
	return (parsed_map);
}
