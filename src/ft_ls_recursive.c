/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:19:01 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 15:43:40 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_isdir(char *name)
{
	struct stat *type;

	type = malloc(sizeof(struct stat));
	stat(name, type);
	return S_ISREG(type->st_mode);
}

int		ft_all_filter(char *name, t_ls_flags *flags)
{
	if (flags->a > 0)
		return (1);
	else if (name[0] == '.' && ft_strlen(name) > 1)
		return (0);
	else
		return (1);
}

void	ft_ls_recursive(t_ls_flags *flags)
{
	DIR				*new;
	DIR				*temp;
	struct dirent 	*sd;

	// ft_ls_tolist(files, flags);
	new = opendir(".");
	while ((sd = readdir(new)) != NULL)
	{
		if (!ft_ls_isdir(sd->d_name) && ft_all_filter(sd->d_name, flags))
		{
			temp = opendir(sd->d_name);
			ft_ls_direct(flags, sd->d_name, 4);
			closedir(temp);
			ft_putchar('\n');
		}
	}
	closedir(temp);
}