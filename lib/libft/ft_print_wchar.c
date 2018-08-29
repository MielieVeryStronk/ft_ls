/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:31:02 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 15:13:07 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_wchar(wint_t c)
{
	int		size;

	size = 0;
	if (c >= 0 && c <= 127)
		size = 1;
	else if (c >= 128 && c <= 2047)
		size = 2;
	else if (c >= 2048 && c <= 65535)
		size = 3;
	else if (c >= 65536 && c <= 1114111)
		size = 4;
	ft_putwchar(c);
	return (size);
}
