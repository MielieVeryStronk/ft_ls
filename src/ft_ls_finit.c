/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_finit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:08:52 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 12:45:22 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_finit(t_ls_fl *flags)
{
	flags->a = 0;
	flags->dr = 0;
	flags->l = 0;
	flags->r = 0;
	flags->t = 0;
	flags->file = 0;
	flags->lenbyte = 0;
	flags->lenlink = 0;
}
