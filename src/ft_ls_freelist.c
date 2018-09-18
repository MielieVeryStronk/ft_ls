/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_freelist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:41:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 16:08:14 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_freelist(t_node *list)
{
    t_node *temp;

    while (list)
    { 
		temp = list;
        list = list->next;
        if (temp->date)
            free(temp->date);
        if (temp->name)
            free(temp->name);
        if (temp->group)
            free(temp->group);
        if (temp->owner)
            free(temp->owner);
        temp->next = NULL;
        temp->prev = NULL;
        if (temp)
            free(temp);
    }
}