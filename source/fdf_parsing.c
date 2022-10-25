/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:17:40 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/25 15:29:20 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_file_extension(char *map_file)
{
	if (ft_strlen(map_file) > 4)
	{
		if (ft_strcmp(map_file + ft_strlen(map_file) - 4, ".fdf") == 0)
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
	if (!read_line)
		exit(1);
	while (read_line)
	{
		new_node = ft_lstnew_node(read_line);
		ft_lstadd_back(&parsing_list, new_node);
		read_line = get_next_line(map_fd);
	}
	return (parsing_list);
}

int	*ft_parse_line(t_list *parsing_list)
{
	char	**split_array;
	int		parsed_number;
	int		*parsed_line;
	int		i;

	i = 0;
	split_array = ft_split(parsing_list->content, ' ');
	parsed_line = my_malloc(sizeof(*parsed_line)
			* (ft_strarray_len(split_array)));
	while (split_array[i])
	{
		parsed_number = ft_atoi(split_array[i]);
		parsed_line[i] = parsed_number;
		free(split_array[i]);
		i++;
	}
	free(split_array);
	return (parsed_line);
}

void	ft_parse_all_lines(char *tmp, t_fdf_map *map,
		t_list *parsing_list, char **split_line)
{
	int	i;

	i = 0;
	while (i < map->row_len)
	{
		tmp = parsing_list->content;
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		split_line = ft_split(parsing_list->content, ' ');
		if ((int)ft_strarray_len(split_line) == map->column_len)
		{
			map->parsed_map[i] = ft_parse_line(parsing_list);
			parsing_list = parsing_list->next;
		}
		else
			exit(1);
		ft_free_split(split_line);
		i++;
	}
}

t_fdf_map	ft_create_parsed_map(t_list *parsing_list)
{
	t_fdf_map	map;
	char		*tmp;
	char		**split_line;
	int			j;

	j = 0;
	tmp = parsing_list->content;
	tmp[ft_strlen(tmp) - 1] = '\0';
	map.row_len = ft_lstsize(parsing_list);
	split_line = ft_split(parsing_list->content, ' ');
	map.column_len = ft_strarray_len(split_line);
	map.parsed_map = my_malloc(sizeof(*map.parsed_map) * map.row_len);
	ft_parse_all_lines(tmp, &map, parsing_list, split_line);
	ft_free_split(split_line);
	return (map);
}
