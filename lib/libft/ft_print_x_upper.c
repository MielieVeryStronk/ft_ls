/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:19:04 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:46:05 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_x_upper(unsigned long long x)
{
	ft_putstr(ft_str_capitalize(ft_ulltoa_base(x, 16)));
	return (ft_strlen(ft_ulltoa_base(x, 16)));
}
