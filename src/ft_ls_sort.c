/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:43:10 by enikel            #+#    #+#             */
/*   Upcdated: 2018/09/12 09:53:30 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_sort_name(node_t **current)
{
	node_t	*curr;
	node_t	*forward;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		curr = *current;
		while (curr && curr->next)
		{
			forward = curr;
			while (forward->name && forward->next->name)
			{
				if (ft_strcmp(forward->name, forward->next->name) > 0)
				{
					ft_ls_sort_switch(current, forward);
					swap = 1;
				}
				forward = forward->next;
			}
			curr = curr->next;
		}
	}
}

void	ft_ls_sort_rev(node_t **current)
{
	node_t	*curr;
	node_t	*forward;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		curr = *current;
		while (curr && curr->next)
		{
			forward = curr;
			while (forward->name && forward->next->name)
			{
				if (ft_strcmp(forward->name, forward->next->name) < 0)
				{
					ft_ls_sort_switch(current, forward);
					swap = 1;
				}
				forward = forward->next;
			}
			curr = curr->next;
		}
	}
}

void	ft_ls_sort_date(node_t **current)
{
	node_t	*curr;
	node_t	*forward;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		curr = *current;
		while (curr && curr->next)
		{
			forward = curr;
			while (forward->cdate && forward->next->cdate)
			{
				if (forward->cdate > forward->next->cdate)
				{
					ft_ls_sort_switch(current, forward);
					swap = 1;
				}
				forward = forward->next;
			}
			curr = curr->next;
		}
	}
}

void	ft_ls_sort_rdate(node_t **current)
{
	node_t	*curr;
	node_t	*forward;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		curr = *current;
		while (curr && curr->next)
		{
			forward = curr;
			while (forward->cdate && forward->next->cdate)
			{
				if (forward->cdate < forward->next->cdate)
				{
					ft_ls_sort_switch(current, forward);
					swap = 1;
				}
				forward = forward->next;
			}
			curr = curr->next;
		}
	}
}

void	ft_ls_sort(node_t **current, t_ls_flags *flags)
{
	if (ft_isflag(flags) == 0)
		ft_ls_sort_name(current);
	else if (flags->t > 0 && flags->r == 0)
		ft_ls_sort_date(current);
	else if (flags->r > 0 && flags->t == 0)
		ft_ls_sort_rev(current);
	else if (flags->r > 0 && flags->t > 0)
		ft_ls_sort_rdate(current);
}