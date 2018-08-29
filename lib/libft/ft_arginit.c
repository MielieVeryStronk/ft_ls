/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arginit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:24:47 by enikel            #+#    #+#             */
/*   Updated: 2018/08/28 09:34:40 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arginit(t_arg *arg)
{
	arg->width = 0;
	arg->justify = 0;
	arg->precision = 0;
	arg->hash = 0;
	arg->z_fill = ' ';
	arg->sign = 0;
	arg->ret = 0;
	arg->spec = 0;
	arg->index = 0;
	arg->search = 0;
	arg->h = 0;
	arg->l = 0;
	arg->z = 0;
	arg->j = 0;
}
