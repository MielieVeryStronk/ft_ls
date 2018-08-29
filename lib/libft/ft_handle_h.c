/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:29:20 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 15:28:18 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	*ft_handle_h(t_arg *arg, va_list valist)
{
	if (arg->spec == 'd')
		arg->ret = arg->ret + ft_print_d(va_arg(valist, long int));
	if (arg->spec == 'D')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, int));
	if (arg->spec == 'i')
		arg->ret = arg->ret + ft_print_d(va_arg(valist, int));
	if (arg->spec == 'x')
		arg->ret = arg->ret + ft_print_x(va_arg(valist, unsigned int));
	if (arg->spec == 'X')
		arg->ret = arg->ret + ft_print_x_upper(va_arg(valist, unsigned int));
	if (arg->spec == 'u')
		arg->ret = arg->ret + ft_print_u(va_arg(valist, unsigned int));
	if (arg->spec == 'U')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, unsigned int));
	if (arg->spec == 'o')
		arg->ret = arg->ret + ft_print_o(va_arg(valist, unsigned int));
	if (arg->spec == 'O')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, unsigned int));
	return (arg);
}
