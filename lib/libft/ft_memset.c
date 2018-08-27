/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:57:44 by enikel            #+#    #+#             */
/*   Updated: 2018/05/21 15:04:20 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (len != 0)
	{
		str[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
