/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:40:24 by romvan-d          #+#    #+#             */
/*   Updated: 2022/10/18 14:47:05 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_node(void *content)
{
	t_list	*lst_new;

	lst_new = malloc(sizeof(*lst_new));
	if (!lst_new)
		exit(1);
	lst_new->content = (void *)content;
	lst_new->next = NULL;
	return (lst_new);
}
