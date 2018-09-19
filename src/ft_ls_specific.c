/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:00:33 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 08:06:48 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_specific(t_node *list, t_ls_fl *flags, char *name)
{
	t_node *current;

	current = list;
	while (current != NULL)
	{
		if (ft_strcmp(name, current->name) == 0)
		{
			ft_print_list(current, flags);
			break ;
		}
		current = current->next;
	}
}
