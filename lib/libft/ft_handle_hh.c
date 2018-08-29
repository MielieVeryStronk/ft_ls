/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:01:26 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 10:35:56 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_hhd(char c)
{
	return (ft_print_d(c));
}

int		ft_char_hhu(t_arg *arg, unsigned char c)
{
	if (arg->spec == 'u')
		return (ft_print_u(c));
	else if (arg->spec == 'o')
		return (ft_print_o(c));
	else if (arg->spec == 'x')
		return (ft_print_x(c));
	else if (arg->spec == 'X')
		return (ft_print_x_upper(c));
	else
		return (0);
}

t_arg	*ft_handle_hh(t_arg *arg, va_list valist)
{
	if (arg->spec == 'd')
		arg->ret = arg->ret + ft_char_hhd(va_arg(valist, int));
	if (arg->spec == 'D')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, int));
	if (arg->spec == 'i')
		arg->ret = arg->ret + ft_char_hhd(va_arg(valist, int));
	if (arg->spec == 'x')
		arg->ret = arg->ret + ft_char_hhu(arg, va_arg(valist, unsigned));
	if (arg->spec == 'X')
		arg->ret = arg->ret + ft_char_hhu(arg, va_arg(valist, unsigned));
	if (arg->spec == 'u')
		arg->ret = arg->ret + ft_char_hhu(arg, va_arg(valist, unsigned));
	if (arg->spec == 'U')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, unsigned));
	if (arg->spec == 'o')
		arg->ret = arg->ret + ft_char_hhu(arg, va_arg(valist, unsigned));
	if (arg->spec == 'O')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, unsigned));
	return (arg);
}
