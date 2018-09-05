/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:19:04 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:48:19 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_x_upper(unsigned long long x)
{
	char	*str;
	int		len;

	str = ft_ulltoa_base(x, 16);
	ft_putstr(ft_str_capitalize(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}
