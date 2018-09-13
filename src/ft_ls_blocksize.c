/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_blocksize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:12:19 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 08:57:04 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_blocksize(t_node *current)
{
	int		ret;

	ret = 0;
	while (current != NULL)
	{
		ret = ret + current->block;
		current = current->next;
	}
	return (ret);
}
