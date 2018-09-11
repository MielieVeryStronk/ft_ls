/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:19:01 by enikel            #+#    #+#             */
/*   Updated: 2018/09/11 13:50:09 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_isdir(char *name)
{
	struct stat s;
	if( stat(name, &s) == 0 )
	{
		if( s.st_mode & S_IFDIR )
			return(1);
		else if( s.st_mode & S_IFREG )
			return(0);
		else
			return(0);
	}
	else
		return (0);
}

int		ft_ls_filter(char *name, t_ls_flags *flags)
{
	if (flags->a > 0 && ft_strcmp(name, ".") && ft_strcmp(name, ".."))
		return (1);
	else if (flags->a == 0 && name[0] != '.')
		return (1);
	else
		return (0);
}

void	ft_ls_repath(t_ls_flags *flags, char *path)
{
	struct dirent	*sd;
	DIR				*temp;

	temp = opendir(path);
	while ((sd = readdir(temp)) != NULL)
	{
		if (ft_ls_isdir(sd->d_name) && ft_ls_filter(sd->d_name, flags))
		{
			//ft_ls_repath(flags, ft_strjoin(path, sd->d_name));
			ft_ls_direct(flags, sd->d_name, 4);
			ft_putchar('\n');
		}
	}
	closedir(temp);
}

void	ft_ls_recursive(t_ls_flags *flags, char *path)
{
	DIR				*dir;
	struct dirent 	*sd;
	char			*repath;
	
	dir = opendir(path);
	if (!ft_strcmp(path, "."))
		ft_ls_direct(flags, path, 4);
	while ((sd = readdir(dir)) != NULL)
	{
		repath = ft_strjoin(path, "/");
		if (ft_ls_isdir(ft_strjoin(repath, sd->d_name)) && ft_ls_filter(sd->d_name, flags))
		{
			ft_putchar('\n');
			repath = ft_strjoin(repath, sd->d_name);
			ft_ls_direct(flags, repath, 4);
			ft_ls_recursive(flags, repath);
		}
	}
	closedir(dir);
}