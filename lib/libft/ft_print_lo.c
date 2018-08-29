/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:18:53 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:42:20 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_lo(unsigned long o)
{
	ft_putstr(ft_ulltoa_base(o, 8));
	return (ft_strlen(ft_ulltoa_base(o, 8)));
}
