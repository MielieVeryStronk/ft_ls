/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:48:17 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:45:11 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_p(long p)
{
	char	*str;
	int		len;

	ft_putstr("0x");
	str = ft_itoa_base(p, 8);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
