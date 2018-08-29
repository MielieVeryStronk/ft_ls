/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:27:00 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:50:41 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_lu(unsigned long long u)
{
	ft_putstr(ft_ulltoa_base(u, 10));
	return (ft_strlen(ft_ulltoa_base(u, 10)));
}
