/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:46:23 by romvan-d          #+#    #+#             */
/*   Updated: 2022/09/18 21:42:45 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int main(int argc, char **argv)
{
    int     fd;
    t_list  *parsing_list;
    int     **parsed_map;
    
    if (argc == 2)
    {
        if (ft_check_file_extension(argv[1]) == 1)
        {
            fd = open(argv[1], O_RDONLY);
            parsing_list = ft_convert_map_to_list(fd);
            parsed_map = ft_create_parsed_map(parsing_list);
        }
    }
    return (0);
}