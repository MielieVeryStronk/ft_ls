/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:04:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 16:19:53 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_list(t_node *current, t_ls_fl *flags)
{
	if (flags->l > 0)
		ft_ls_l(current, flags);
	ft_printf("%s", current->name);
	if (flags->file == 0)
		ft_printf("\n");
}
