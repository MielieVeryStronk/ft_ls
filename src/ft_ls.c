/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:24:31 by enikel            #+#    #+#             */
/*   Updated: 2018/08/29 14:40:01 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
	DIR             *dir;
	struct dirent   *sd;
	char			*out;
	t_ls_flags		flags;
	//struct stat		info;

	ft_ls_finit(&flags);
	dir = opendir(".");
	if (dir == NULL && argv[0])
	{
		ft_putstr("ERROR MESSAGE");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL && argc == 1)
	{
		out = sd->d_name;
		if (out[0] != '.')
			ft_printf("%s\n", out);
	}
	closedir(dir);
	return (0);
}