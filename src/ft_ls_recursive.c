/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:19:01 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 08:24:35 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_filter(char *name, t_ls_fl *flags)
{
	if (flags->a > 0 && ft_strcmp(name, ".") && ft_strcmp(name, ".."))
		return (1);
	else if (flags->a == 0 && name[0] != '.')
		return (1);
	else
		return (0);
}

void	ft_ls_repath(t_ls_fl *flags, char *path)
{
	struct dirent	*sd;
	DIR				*temp;

	temp = opendir(path);
	while ((sd = readdir(temp)) != NULL)
	{
		if (ft_ls_isdir(sd->d_name) && ft_ls_filter(sd->d_name, flags))
		{
			ft_ls_direct(flags, sd->d_name, 4);
			ft_putchar('\n');
		}
	}
	closedir(temp);
}

void	ft_ls_re(char *repath, char *temp, struct dirent *sd, t_ls_fl *flags)
{
	if (ft_ls_isdir(temp)
	&& ft_ls_filter(sd->d_name, flags))
	{
		ft_putchar('\n');
		free(temp);
		temp = ft_strjoin(repath, sd->d_name);
		ft_ls_direct(flags, temp, 4);
		ft_ls_recursive(flags, temp);
	}
	if (repath)
		free(repath);
	if (temp)
		free(temp);
}

void	ft_ls_recursive(t_ls_fl *flags, char *path)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*repath;
	char			*temp;

	dir = opendir(path);
	if (dir == NULL)
		ft_ls_exit(2, path);
	if (!ft_strcmp(path, "."))
		ft_ls_direct(flags, path, 4);
	while ((sd = readdir(dir)) != NULL)
	{
		repath = ft_strjoin(path, "/");
		temp = ft_strjoin(repath, sd->d_name);
		ft_ls_re(repath, temp, sd, flags);
	}
	closedir(dir);
}
