/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:10:32 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:45:07 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_x(unsigned long long x)
{
	ft_putstr(ft_ulltoa_base(x, 16));
	return (ft_strlen(ft_ulltoa_base(x, 16)));
}
