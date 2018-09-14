/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:29:04 by enikel            #+#    #+#             */
/*   Updated: 2018/09/14 07:53:50 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_exit(int err, char *var)
{
	if (err == 1)
	{
		printf("ft_ls: illegal option -- %c\n", *var);
		printf("usage: ft_ls [-Rralt] [file ...]");
	}
	else if (err == 2)
		printf("ft_ls: %s: No such file or directory", var);
	else if (err == 3)
		printf("malloc error");
	exit(err);
}
