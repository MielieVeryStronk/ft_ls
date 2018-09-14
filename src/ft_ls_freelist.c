/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_freelist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:41:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/14 16:46:18 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_freelist(t_node *list)
{
    while (list != NULL)
    { 
        t_node *temp;

		temp = list;
        list = list->next;
        free(temp->date);
        free(temp->name);
        free(temp->group);
        free(temp->owner);
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}