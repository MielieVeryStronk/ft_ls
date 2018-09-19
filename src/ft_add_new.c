/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:40:32 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 11:41:48 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_add_new(t_node **current, t_node **prev)
{
	if (!*current)
	{
		*current = ft_memalloc(sizeof(t_node));
		(*current)->prev = *prev;
		(*prev)->next = *current;
	}
	else
		(*current)->prev = NULL;
}
