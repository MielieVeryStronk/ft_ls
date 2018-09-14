/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:24:31 by enikel            #+#    #+#             */
/*   Updated: 2018/09/14 16:54:54 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void			ft_ls_flagorder(t_ls_fl *flags, char *path)
{
	DIR				*dir;
	t_node			*files;

	if (!(files = malloc(sizeof(t_node))))
		ft_ls_exit(3, NULL);
	if (flags->dr > 0)
	{
		dir = opendir("./");
		ft_ls_recursive(flags, path);
	}
	else
	{
		dir = opendir("./");
		ft_ls_tolist(dir, files, flags, path);
	}
	if (dir == NULL)
		ft_ls_exit(2, "./");
	closedir(dir);
	ft_ls_freelist(files);
}

t_ls_fl		*ft_ls_hflags(char *args, t_ls_fl *flags)
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

int				main(int argc, char **argv)
{
	t_ls_fl		*flags;
	int				i;

	i = 1;
	if (!(flags = ft_memalloc(sizeof(t_ls_fl))))
		ft_ls_exit(3, NULL);
	ft_ls_finit(flags);
	if (argc > 1)
	{
		flags = ft_ls_hflags(argv[1], flags);
		if (argv[1][0] == '-' && ft_isflag(flags) && argc == 2) // flags and no filenames
			ft_ls_flagorder(flags, ".");
		else if (argv[1][0] == '-' && !ft_isflag(flags))
			ft_ls_exit(2, argv[1]);
		else if (argv[1][0] != '-') // no flags with filenames
			while (i < argc)
			{
				if (ft_ls_isdir(argv[i]))
					ft_ls_direct(flags, argv[i++], argc);
				else
					ft_ls_file(flags, argv[i++]);
			}
		else if (argv[1][0] == '-' && argc > 2) // flags + filenames
		{
			i = 2;
			if (flags->dr > 0)
			{
				while (i < argc)
				{
					ft_ls_direct(flags, argv[i], 4);
					ft_ls_flagorder(flags, argv[i++]);
				}
			}
			else while (i < argc)
			{
				if (ft_ls_isdir(argv[i]))
					ft_ls_direct(flags, argv[i++], argc);
				else
					ft_ls_file(flags, argv[i++]);
				if (i < argc)
					ft_putchar('\n');
			}
		}
	}
	else
	{
		ft_ls_flagorder(flags, "."); // no flags no filenames
	}
	free(flags);
	printf("SLEEP\n");
	sleep(10);
	return (0);
}
