/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_switch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:05:29 by enikel            #+#    #+#             */
/*   Updated: 2018/09/17 14:09:06 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort_switch(t_node **start, t_node *current)
{
	t_node *prev;
	t_node *next;
	t_node *tmp;

	prev = current->prev;
	next = current->next;
	tmp = next->next;
	if (!prev)
		*start = next;
	else
		prev->next = next;
	if (tmp)
		tmp->prev = current;
	next->next = current;
	next->prev = prev;
	current->prev = next;
	current->next = tmp;
}
