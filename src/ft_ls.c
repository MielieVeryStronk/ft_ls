/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:24:31 by enikel            #+#    #+#             */
/*   Updated: 2018/08/30 12:36:42 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <stdio.h>

void	ft_ls_flagorder(t_ls_flags *flags)
{
	DIR				*dir;
	node_t 			*files;
	
	files = malloc(sizeof(node_t));
	if (files == NULL)
    	exit(1);
	dir = opendir(".");
	ft_ls_tolist(dir, files, flags);
	if (dir == NULL)
		ft_ls_exit(2, ".");
	closedir(dir);
}

t_ls_flags		*ft_ls_hflags(char *args, t_ls_flags *flags)
{
	int				i;

	i = 0;
	if (args[i] == '-')
	{
		i++;
		while (args[i] != '\0')
		{
			if (args[i] == 'a')
				flags->a++;
			else if (args[i] == 'l')
				flags->l++;
			else if (args[i] == 'r')
				flags->r++;
			else if (args[i] == 'R')
				flags->dr++;
			else if (args[i] == 't')
				flags->t++;
			else
				ft_ls_exit(1, &args[i]);
			i++;
		}
	}
	return (flags);
}

int     main(int argc, char **argv)
{
	// DIR             *dir;
	// struct dirent   *sd;
	// char			*out;
	t_ls_flags		*flags;

	flags = malloc(sizeof(t_ls_flags) + 16);
	ft_ls_finit(flags);
	// dir = opendir(".");
	// if (dir == NULL)
	// {
	// 	ft_putstr("ERROR MESSAGE");
	// 	exit(1);
	// }
	if (argc > 1)
	{
		flags = ft_ls_hflags(argv[1], flags);
		if (argv[1][0] == '-')
			ft_ls_flagorder(flags);
	}
	// else while ((sd = readdir(dir)) != NULL && argc == 1)
	// {
	// 	out = sd->d_name;
	// 	if (out[0] != '.')
	// 		ft_printf("%s\n", out);
	// }
	// closedir(dir);
	return (0);
}