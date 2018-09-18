/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 08:16:57 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 08:32:47 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort_rev(t_node **start)
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
				if (ft_strcmp(forward->name, forward->next->name) < 0)
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

void	ft_ls_sort_date(t_node **start)
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
				if (forward->cdate > forward->next->cdate)
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

void	ft_ls_sort_rdate(t_node **start)
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
				if (forward->cdate < forward->next->cdate)
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

void	ft_ls_sort(t_node **start, t_ls_fl *flags)
{
	if (flags->t == 0 && flags->r == 0)
		ft_ls_sort_name(start);
	else if (flags->t > 0 && flags->r == 0)
		ft_ls_sort_date(start);
	else if (flags->r > 0 && flags->t == 0)
		ft_ls_sort_rev(start);
	else if (flags->r > 0 && flags->t > 0)
		ft_ls_sort_rdate(start);
}
