/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arghandle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:32:08 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 16:28:56 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arghandle(const char *format, va_list valist)
{
	t_arg	*arg;
	int		rtemp;

	arg = malloc(sizeof(t_arg) + 16);
	ft_arginit(arg);
	if (*format == '\0')
		return (arg->ret);
	while (format[arg->index] != '\0')
	{
		if (format[arg->index] == '%')
		{
			ft_arg_reset_mod(arg);
			arg = ft_hspec(format, arg, valist);
			arg->index = arg->search;
		}
		else if (ft_isascii(format[arg->index]) && format[arg->index] != '\0')
		{
			ft_putchar(format[arg->index]);
			arg->ret++;
		}
		if (format[arg->index] != '\0')
			arg->index++;
	}
	rtemp = arg->ret;
	free(arg);
	return (rtemp);
}
