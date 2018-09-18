/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:20:37 by enikel            #+#    #+#             */
/*   Updated: 2018/09/17 16:13:47 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node		**ft_ls_tail(t_node **head)
{
	t_node	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}