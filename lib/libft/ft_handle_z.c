/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:04:28 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:54:58 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	*ft_handle_z(t_arg *arg, va_list valist)
{
	if (arg->spec == 'd')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, size_t));
	if (arg->spec == 'D')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, size_t));
	if (arg->spec == 'i')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, size_t));
	if (arg->spec == 'x')
		arg->ret = arg->ret + ft_print_x(va_arg(valist, size_t));
	if (arg->spec == 'X')
		arg->ret = arg->ret + ft_print_x_upper(va_arg(valist, size_t));
	if (arg->spec == 'u')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, size_t));
	if (arg->spec == 'U')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, size_t));
	if (arg->spec == 'o')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, size_t));
	if (arg->spec == 'O')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, size_t));
	return (arg);
}
