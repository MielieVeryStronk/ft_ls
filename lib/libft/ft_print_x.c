/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:10:32 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:46:57 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_x(unsigned long long x)
{
	char	*str;
	int		len;

	str = ft_ulltoa_base(x, 16);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
