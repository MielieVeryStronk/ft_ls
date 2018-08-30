/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:48:22 by enikel            #+#    #+#             */
/*   Updated: 2018/08/30 15:49:16 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_permission(int c)
{
	if (c == '0')
		ft_putstr("---");
	else if (c == '1')
		ft_putstr("--x");
	else if (c == '2')
		ft_putstr("-w-");
	else if (c == '3')
		ft_putstr("-wx");
	else if (c == '4')
		ft_putstr("r--");
	else if (c == '5')
		ft_putstr("r-x");
	else if (c == '6')
		ft_putstr("rw-");
	else if (c == '7')
		ft_putstr("rwx");
}

void	ft_print_mode(unsigned mode)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base(mode, 8);
	if (i == 0 && str[i] == '1')
	{
		ft_putchar('-');
		i = 3;
	}
	else
	{
		ft_putchar('d');
		i = 2;
	}
	while (str[i] != '\0')
	{
		ft_print_permission(str[i]);
		i++;
	}
	ft_putstr("  ");
}

void	ft_ls_l(node_t *current)
{
	if (current->mode)
		ft_print_mode(current->mode);
}