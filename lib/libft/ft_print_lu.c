/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:27:00 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:43:24 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_lu(unsigned long long u)
{
	char	*str;
	int		len;

	str = ft_ulltoa_base(u, 10);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
