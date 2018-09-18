/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:32:09 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 08:32:24 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort_name(t_node **start)
{
	t_node	*curr;
	t_node	*forward;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		curr = *start;
		while (curr && curr->next)
		{
			forward = curr;
			while (forward && forward->next)
			{
				if (ft_strcmp(forward->name, forward->next->name) > 0)
				{
					ft_ls_sort_switch(start, forward);
					swap = 1;
				}
				forward = forward->next;
			}
			curr = curr->next;
		}
	}
}