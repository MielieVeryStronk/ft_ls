/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:27:26 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 15:34:40 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_direct(t_ls_flags *flags, char *dirname, int argc)
{
	DIR				*dir;
	node_t 			*files;

	if (ft_isflag(flags))
		argc--;
	files = malloc(sizeof(node_t));
	if (files == NULL)
    	exit(1);
	dir = opendir(dirname); //	if ((dir = opendir(dirname)) == NULL && ft_ls_isfile(dirname))
	if (argc > 2 && ft_strcmp(".", dirname))
		ft_printf("%s:\n", dirname);
	ft_ls_tolist(dir, files, flags);
	if (dir == NULL)
		ft_ls_exit(2, dirname);
	closedir(dir);
}