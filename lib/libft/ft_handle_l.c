/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:59:18 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:49:20 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	*ft_handle_l(t_arg *arg, va_list valist)
{
	if (arg->spec == 's')
		arg->ret = arg->ret + ft_print_wstr(va_arg(valist, wchar_t *));
	if (arg->spec == 'c')
		arg->ret = arg->ret + ft_print_wchar(va_arg(valist, wchar_t));
	if (arg->spec == 'd')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, long int));
	if (arg->spec == 'D')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, long int));
	if (arg->spec == 'i')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, long int));
	if (arg->spec == 'x')
		arg->ret = arg->ret + ft_print_x(va_arg(valist, long unsigned int));
	if (arg->spec == 'X')
		arg->ret = arg->ret + ft_print_x_upper(va_arg(valist, long unsigned));
	if (arg->spec == 'u')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, unsigned long));
	if (arg->spec == 'U')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, long unsigned int));
	if (arg->spec == 'o')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, long long unsigned));
	if (arg->spec == 'O')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, long unsigned int));
	return (arg);
}
