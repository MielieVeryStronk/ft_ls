/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:07:57 by enikel            #+#    #+#             */
/*   Updated: 2018/06/14 09:57:21 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int		i;
	int						c;
	int						neg;

	c = 0;
	i = 0;
	while ((str[c] == '\n') || (str[c] == '\t') || (str[c] == '\r') ||
			(str[c] == '\f') || (str[c] == ' ') || (str[c] == '\v'))
		c++;
	if (str[c] == '+' && ft_isdigit(str[c + 1]))
		c++;
	if (str[c] == '-' && ft_isdigit(str[c + 1]))
	{
		neg = 1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
		i = i * 10 + (str[c++] - 48);
	if (i > 9223372036854775807 && neg == 1)
		return (0);
	if (i > 9223372036854775807)
		return (-1);
	if (neg == 1)
		return (i * -1);
	return (i);
}
