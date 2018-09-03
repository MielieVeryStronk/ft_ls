/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:24:31 by enikel            #+#    #+#             */
/*   Updated: 2018/09/03 14:30:01 by enikel           ###   ########.fr       */
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

int		ft_isflag(t_ls_flags *flags)
{
	if (flags->a > 0 || flags->dr > 0 || flags->l > 0 || flags->r > 0
	|| flags->t > 0)
		return (1);
	else
		return (0);
}

int     main(int argc, char **argv)
{
	t_ls_flags		*flags;

	flags = malloc(sizeof(t_ls_flags) + 16);
	ft_ls_finit(flags);
	if (argc > 1)
	{
		flags = ft_ls_hflags(argv[1], flags);
		if (argv[1][0] == '-' && ft_isflag(flags) && argc == 2)
			ft_ls_flagorder(flags);
		else if (argv[1][0] == '-' && !ft_isflag(flags))
			ft_ls_exit(2, argv[1]);
		// else
		// 	ft_ls_direct(argv);
	}
	else
		ft_ls_flagorder(flags);
	return (0);
}