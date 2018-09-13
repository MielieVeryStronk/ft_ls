/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:27:26 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 16:26:14 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_direct(t_ls_fl *flags, char *dirname, int argc)
{
	DIR				*dir;
	t_node			*files;

	if (ft_isflag(flags))
		argc--;
	if (!(files = malloc(sizeof(t_node))))
		ft_ls_exit(3, NULL);
	if (files == NULL)
		exit(1);
	dir = opendir(dirname);
	if (dir == NULL)
		ft_ls_exit(2, dirname);
	if (argc > 2 && ft_strcmp(".", dirname))
		ft_printf("%s:\n", dirname);
	ft_ls_tolist(dir, files, flags, dirname);
	closedir(dir);
}
