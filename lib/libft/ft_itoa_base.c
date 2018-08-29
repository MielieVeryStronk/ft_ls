/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:18:43 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 13:30:34 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long int n, int base)
{
	long int		num;
	static int		i;
	static char		*str;

	num = (long int)n;
	i = 0;
	str = ft_strnew(ft_intlen(num) + 1);
	str[ft_intlen(num)] = '\0';
	if (num < 0)
	{
		num = -num;
		str[i] = '-';
		i++;
	}
	if (num >= base)
	{
		free(str);
		ft_itoa_base(num / base, base);
	}
	if (num % base > 9)
		str[i++] = (char)((num % base) + 87);
	else
		str[i++] = (char)((num % base) + 48);
	return (str);
}
