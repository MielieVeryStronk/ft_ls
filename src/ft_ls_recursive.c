/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:19:01 by enikel            #+#    #+#             */
/*   Updated: 2018/09/06 15:58:59 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_isnotdir(char *name)
{
	struct stat *type;

	type = malloc(sizeof(struct stat));
	stat(name, type);
	return S_ISREG(type->st_mode);
}

int		ft_ls_filter(char *name, t_ls_flags *flags)
{
	if (flags->a > 0)
		return (1);
	else if (name[0] == '.' && ft_strlen(name) > 1)
		return (0);
	else
		return (1);
}

void	ft_ls_repath(t_ls_flags *flags, char *path)
{
	struct dirent	*sd;
	DIR				*temp;

	temp = opendir(path);
	while ((sd = readdir(temp)) != NULL)
		if (!ft_ls_isnotdir(sd->d_name) && ft_ls_filter(sd->d_name, flags))
		{
			//ft_ls_repath(flags, ft_strjoin(path, sd->d_name));
			ft_ls_direct(flags, path, 4);
			ft_putchar('\n');
		}
	closedir(temp);
}

void	ft_ls_recursive(t_ls_flags *flags, char *path)
{
	DIR				*dir;
	struct dirent 	*sd;


	// ft_ls_tolist(files, flags);
	dir = opendir(path);
	while ((sd = readdir(dir)) != NULL)
	{
		if (!ft_ls_isnotdir(sd->d_name) && ft_ls_filter(sd->d_name, flags))
		{
			ft_ls_direct(flags, sd->d_name, 4);
			//ft_printf("THIS : %s", ft_strjoin("./", sd->d_name));
			ft_ls_repath(flags, ft_strjoin("./", sd->d_name));
			ft_putchar('\n');
		}
	}
	closedir(dir);
}