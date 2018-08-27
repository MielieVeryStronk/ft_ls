/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:24:30 by enikel            #+#    #+#             */
/*   Updated: 2018/05/24 10:44:59 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	chr;
	int		a;
	int		b;

	a = 0;
	b = ft_strlen(str) - 1;
	if (b == 0)
		return (str);
	while (a < b)
	{
		chr = str[a];
		str[a] = str[b];
		str[b] = chr;
		a++;
		b--;
	}
	return (str);
}
