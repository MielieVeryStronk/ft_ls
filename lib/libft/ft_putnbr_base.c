/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:37:35 by enikel            #+#    #+#             */
/*   Updated: 2018/07/10 14:30:04 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long int n, int base)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		num = -num;
		ft_putchar('-');
	}
	if (num > base)
		ft_putnbr_base(num / base, base);
	if (num % base > 9)
		ft_putchar((num % base) + 87);
	else
		ft_putchar((num % base) + 48);
}
