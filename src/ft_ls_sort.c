/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:43:10 by enikel            #+#    #+#             */
/*   Updated: 2018/08/31 14:07:46 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void swap(node_t *a, node_t *b)
{
	node_t	*temp;
    
	temp = a;
    a = b;
    b = temp;
}

void	ft_sort_name(node_t *files)
{
	int	swapped;
	node_t *ptr1;
    node_t *lptr;

	swapped = 0;
    ptr1 = files;
	lptr = NULL;
 
	while (ptr1->next != lptr)
	{
		if (ft_strcmp(ptr1->name, ptr1->next->name) < 0)
		{ 
			swap(ptr1, ptr1->next);
			swapped = 1;
		}
		ptr1 = ptr1->next;
	}
	lptr = ptr1;
}

void	ft_ls_sort(node_t *files, t_ls_flags *flags)
{
	if (flags->l > 0)
		ft_sort_name(files);
}