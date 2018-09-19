/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:33:36 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 11:41:50 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_afilter(t_node *list, t_ls_fl *flags)
{
	t_node *current;

	current = list;
	if (flags->l > 0)
		ft_printf("total %d\n", ft_ls_blocksize(current));
	while (current != NULL)
	{
		if (current->name && flags->a > 0)
			ft_print_list(current, flags);
		else if (current->name && flags->a == 0 && current->name[0] != '.')
			ft_print_list(current, flags);
		current = current->next;
	}
}

void	ft_get_details(t_node *current, struct stat *details, t_ls_fl *flags)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(details->st_uid);
	current->owner = ft_strdup(pwd->pw_name);
	grp = getgrgid(details->st_gid);
	current->group = ft_strdup(grp->gr_name);
	current->mode = details->st_mode;
	current->links = details->st_nlink;
	current->bytes = details->st_size;
	current->cdate = details->st_mtime;
	current->date = ft_strdup(ctime(&details->st_mtime));
	current->block = details->st_blocks;
	if (ft_intlen(current->bytes) > flags->lenbyte)
		flags->lenbyte = ft_intlen(current->bytes);
	if (ft_intlen(current->links) > flags->lenlink)
		flags->lenlink = ft_intlen(current->links);
}

void	ft_filefilter(t_node *files, t_ls_fl *flags, char *path)
{
	if (flags->file == 0)
	{
		ft_ls_sort(&files, flags);
		ft_afilter(files, flags);
		if (flags->r > 0 || flags->t > 0)
			ft_ls_sort_name(&files);
	}
	else
	{
		path[ft_strlen(path) - 1] = '\0';
		path = ft_strrchr(path, '/');
		path++;
		ft_ls_specific(files, flags, path);
	}
	if (path)
		free(path);
}

void	ft_stat_d(struct stat *details, char *path, struct dirent *sd, int f)
{
	char *temp;

	temp = ft_strjoin(path, sd->d_name);
	if (f == 0)
		stat(temp, details);
	else
		stat(path, details);
	if (temp)
		free(temp);
}

void	ft_ls_tolist(DIR *dir, t_node *files, t_ls_fl *flags, char *path)
{
	t_node			*current;
	t_node			*prev;
	struct dirent	*sd;
	struct stat		*details;

	current = files;
	current->prev = NULL;
	if (!(details = malloc(sizeof(struct stat))))
		ft_ls_exit(3, NULL);
	path = ft_ls_checkpath(path);
	while ((sd = readdir(dir)) != NULL)
	{
		ft_add_new(&current, &prev);
		ft_stat_d(details, path, sd, flags->file);
		ft_get_details(current, details, flags);
		current->name = ft_strdup(sd->d_name);
		prev = current;
		current = current->next;
	}
	if (details)
		free(details);
	ft_ls_freelist(current);
	ft_filefilter(files, flags, path);
}
