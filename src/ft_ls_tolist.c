/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:33:36 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 08:08:07 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_list(node_t *current, t_ls_flags *flags)
{
		if (flags->l > 0)
			ft_ls_l(current, flags);
		ft_printf("%s", current->name);
		/*if (flags->l > 0 && current->symlink)
			ft_printf(" -> %s", current->symlink);*/
		ft_printf("\n");
}

void	ft_afilter(node_t *list, t_ls_flags *flags)
{
	node_t *current;

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

void	ft_get_details(node_t *current, struct stat *details)
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
}

char	*ft_checkpath(char *path)
{
	if (path[0] != '/' && path[1] != '/')
		path = ft_strjoin("./", path);
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	return (path);
}

void	ft_ls_tolist(DIR *dir, node_t *files, t_ls_flags *flags, char *path)
{
	node_t 			*current;
	struct dirent	*sd;
	struct stat		*details;

	current = files;
	current->prev = NULL;
	details = malloc(sizeof(struct stat));
	while ((sd = readdir(dir)) != NULL)
	{
		path = ft_checkpath(path);
		stat(ft_strjoin(path, sd->d_name), details);
		ft_get_details(current, details);
		if (ft_intlen(current->bytes) > flags->lenbyte)
			flags->lenbyte = ft_intlen(current->bytes);
		if (ft_intlen(current->links) > flags->lenlink)
			flags->lenlink = ft_intlen(current->links);
		current->name = ft_strdup(sd->d_name);
		//readlink(sd->d_name, current->symlink, details->st_size + 1);
		current->next = malloc(sizeof(node_t));
		current->next->prev = current;
		current = current->next;
	}
	//ft_ls_sort(files, flags);
	current->next = NULL;
	ft_ls_sort(&files, flags);
	ft_afilter(files, flags);
	free(details);
}
