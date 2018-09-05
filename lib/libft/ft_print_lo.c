/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:18:53 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:42:57 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_lo(unsigned long o)
{
	char	*str;
	int		len;

	str = ft_ulltoa_base(o, 8);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
