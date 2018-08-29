/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:53:43 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 14:54:55 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_wstr(wint_t *c)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (c == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (c[i] > 0)
	{
		if (c[i] >= 0 && c[i] <= 127)
			size = size + 1;
		else if (c[i] >= 128 && c[i] <= 2047)
			size = size + 2;
		else if (c[i] >= 2048 && c[i] <= 65535)
			size = size + 3;
		else if (c[i] >= 65536 && c[i] <= 1114111)
			size = size + 4;
		ft_putwchar(c[i]);
		i++;
	}
	return (size);
}
