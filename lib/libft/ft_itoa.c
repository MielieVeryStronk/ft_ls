/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 12:41:40 by enikel            #+#    #+#             */
/*   Updated: 2018/07/10 14:21:37 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = (long int)n;
	i = ft_intlen(num) - 1;
	if (num < 0)
	{
		i++;
		num = num * -1;
	}
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str[i + 1] = '\0';
	while (num > 0)
	{
		str[i--] = (char)((num % 10) + 48);
		num = num / 10;
	}
	if (i == 0 && str[i + 1] > 0)
		str[i] = '-';
	return (str);
}
