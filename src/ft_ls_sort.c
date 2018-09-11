/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:43:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/11 16:12:05 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort(node_t *current)
{
	node_t	*temp;
	node_t	*curr;
	node_t	*forward;

	curr = current;
	while (curr && curr->next)
	{
		forward = curr;
		while (forward->name && forward->next->name)
		{
			if (ft_strcmp(ft_str_capitalize(forward->name), ft_str_capitalize(forward->next->name)) > 0)
			{
				temp = forward->next->next;
				temp->prev = forward;
				forward->next->next = forward;
				forward->prev = forward->next;
				forward->next = temp;
			}
			forward = forward->next;
		}
		curr = curr->next;
	}
} 