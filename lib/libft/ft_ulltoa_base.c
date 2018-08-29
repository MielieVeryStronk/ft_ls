/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:03:11 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 14:14:28 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(uintmax_t n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

static void		ft_iszero(char *new, uintmax_t n)
{
	if (n == 0)
		new[0] = '0';
}

char			*ft_ulltoa_base(uintmax_t n, int base)
{
	size_t				i;
	uintmax_t			tmp;
	char				*new;

	i = ft_getlen(n, base);
	tmp = n;
	if (!(new = ft_strnew(i)))
		return (NULL);
	ft_iszero(new, n);
	while (i--)
	{
		if (tmp % base < 10)
			new[i] = (tmp % base) + '0';
		else if (tmp % base >= 10)
			new[i] = (tmp % base) - 10 + 'a';
		tmp /= base;
	}
	return (new);
}
