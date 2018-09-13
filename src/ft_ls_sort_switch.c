/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_switch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:05:29 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 08:37:54 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort_switch(t_node **start, t_node *node)
{
	t_node *prev;
	t_node *next;
	t_node *tmp;

	prev = node->prev;
	next = node->next;
	tmp = next->next;
	if (!prev)
		*start = next;
	else
		prev->next = next;
	if (tmp)
		tmp->prev = node;
	next->next = node;
	next->prev = prev;
	node->prev = next;
	node->next = tmp;
}
