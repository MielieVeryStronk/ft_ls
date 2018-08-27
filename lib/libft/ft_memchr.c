/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:28:48 by enikel            #+#    #+#             */
/*   Updated: 2018/06/06 08:24:22 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	chr;
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	a = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (a[i] == chr)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
