/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:27:55 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 11:28:16 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_isflag(t_ls_flags *flags)
{
	if (flags->a > 0 || flags->dr > 0 || flags->l > 0 || flags->r > 0
	|| flags->t > 0)
		return (1);
	else
		return (0);
}