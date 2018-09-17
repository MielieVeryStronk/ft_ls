/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:48:22 by enikel            #+#    #+#             */
/*   Updated: 2018/09/17 10:44:17 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_time(char *time)
{
	int	i;

	i = 8;
	if (time[i] == ' ')
	{
		ft_putchar(' ');
		i++;
	}
	while (ft_isdigit(time[i]))
		ft_putchar(time[i++]);
	i = 4;
	ft_putchar(' ');
	while (ft_isalpha(time[i]))
		ft_putchar(time[i++]);
	i = 10;
	while (i < 16)
		ft_putchar(time[i++]);
	ft_putstr(" ");
}

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
	ft_putchar(' ');
	if (str)
		free(str);
}

void	ft_ls_l(t_node *current, t_ls_fl *flags)
{
	int		space;

	space = 4;
	if (current->mode)
		ft_print_mode(current->mode);
	if (current->links)
	{
		space = flags->lenlink - ft_intlen(current->links);
		while (space > 0)
		{
			ft_putchar(' ');
			space--;
		}
		printf("%d ", current->links);
	}
	if (current->owner)
		printf("%s  ", current->owner);
	if (current->group)
		printf("%s  ", current->group);
	if (current->bytes)
		space = flags->lenbyte - ft_intlen(current->bytes);
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
	printf("%lld ", current->bytes);
	if (current->date)
		ft_print_time(current->date);
}
