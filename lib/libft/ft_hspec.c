/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:47:56 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 10:38:14 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	*ft_sort_mod_spec(t_arg *arg, va_list valist)
{
	if (arg->spec == 'd')
		arg->ret = arg->ret + ft_print_d(va_arg(valist, int));
	if (arg->spec == 'D')
		arg->ret = arg->ret + ft_print_ld(va_arg(valist, long int));
	if (arg->spec == 'i')
		arg->ret = arg->ret + ft_print_d(va_arg(valist, int));
	if (arg->spec == 'x')
		arg->ret = arg->ret + ft_print_x(va_arg(valist, unsigned long));
	if (arg->spec == 'X')
		arg->ret = arg->ret + ft_print_x_upper(va_arg(valist, unsigned long));
	if (arg->spec == 'o')
		arg->ret = arg->ret + ft_print_o(va_arg(valist, unsigned int));
	if (arg->spec == 'O')
		arg->ret = arg->ret + ft_print_lo(va_arg(valist, unsigned long));
	if (arg->spec == 'u')
		arg->ret = arg->ret + ft_print_u(va_arg(valist, unsigned int));
	if (arg->spec == 'U')
		arg->ret = arg->ret + ft_print_lu(va_arg(valist, unsigned long));
	if (arg->spec == 'c')
		arg->ret = arg->ret + ft_print_c(va_arg(valist, int));
	if (arg->spec == 's')
		arg->ret = arg->ret + ft_print_s(va_arg(valist, char *));
	return (arg);
}

t_arg	*ft_sort_spec(t_arg *arg, va_list valist)
{
	if (arg->spec == 'p')
		arg->ret = arg->ret + ft_print_p(va_arg(valist, long));
	if (arg->spec == 'C')
		arg->ret = arg->ret + ft_print_wchar(va_arg(valist, wint_t));
	if (arg->spec == 'S')
		arg->ret = arg->ret + ft_print_wstr(va_arg(valist, wint_t *));
	return (arg);
}

t_arg	*ft_sort_mod(t_arg *arg, va_list valist)
{
	if (arg->l == 1 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_l(arg, valist);
	else if (arg->l == 2 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_ll(arg, valist);
	else if (arg->h == 1 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_h(arg, valist);
	else if (arg->h == 2 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_hh(arg, valist);
	else if (arg->j == 1 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_j(arg, valist);
	else if (arg->z == 1 && ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_handle_z(arg, valist);
	else if (ft_strchr(VALID_MOD_SPEC, arg->spec))
		arg = ft_sort_mod_spec(arg, valist);
	else
		arg = ft_sort_spec(arg, valist);
	return (arg);
}

t_arg	*ft_get_mod(const char *format, t_arg *arg)
{
	arg->index++;
	while (ft_strchr(PRINT_LMODS, format[arg->index]))
	{
		if (format[arg->index] == 'l')
			arg->l++;
		if (format[arg->index] == 'h')
			arg->h++;
		if (format[arg->index] == 'z')
			arg->z++;
		if (format[arg->index] == 'j')
			arg->j++;
		arg->index++;
	}
	arg->index--;
	return (arg);
}

t_arg	*ft_hspec(const char *format, t_arg *arg, va_list valist)
{
	arg->search = arg->index + 1;
	while (!ft_strchr(PRINT_SPEC, format[arg->search]))
		arg->search++;
	if (format[arg->search] != '\0')
		arg->spec = format[arg->search];
	if (format[arg->index + 1] == '%')
	{
		ft_putchar('%');
		arg->ret++;
		arg->index = arg->index + 2;
		return (arg);
	}
	else if (arg->spec != 0)
	{
		arg = ft_get_mod(format, arg);
		arg = ft_sort_mod(arg, valist);
	}
	return (arg);
}
