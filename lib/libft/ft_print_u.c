/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:24:42 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:45:31 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_u(unsigned int u)
{
	char	*str;
	int		len;

	str = ft_itoa_base(u, 10);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
