/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:33:36 by enikel            #+#    #+#             */
/*   Updated: 2018/09/07 11:52:10 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_list(node_t *list, t_ls_flags *flags)
{
	node_t *current;

	current = list;
    while (current != NULL)
	{
		if (current->name && flags->a > 0)
		{
			if (flags->l > 0)
				ft_ls_l(current, flags);
        	ft_printf("%s", current->name);
			ft_printf("\n");
		}
		else if (current->name && flags->a == 0 && current->name[0] != '.')
		{
			if (flags->l > 0)
				ft_ls_l(current, flags);
        	ft_printf("%s", current->name);
			ft_printf("\n");
		}
        current = current->next;
	}
}

void	ft_get_details(node_t *current, struct stat *details)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(details->st_uid);
	current->owner = pwd->pw_name;
	grp = getgrgid(details->st_gid);
	current->group = grp->gr_name;
	current->mode = details->st_mode;
	current->links = details->st_nlink;
	current->bytes = details->st_size;
	current->date = ft_strdup(ctime(&details->st_mtime));
}

void	ft_ls_tolist(DIR *dir, node_t *files, t_ls_flags *flags)
{
	node_t 			*current;
	struct dirent	*sd;
	struct stat		*details;

	current = files;
	details = malloc(sizeof(struct stat));
	while ((sd = readdir(dir)) != NULL)
	{
		stat(sd->d_name, details);
		ft_get_details(current, details);
		if (ft_intlen(current->bytes) > flags->lenbyte)
			flags->lenbyte = ft_intlen(current->bytes);
		if (ft_intlen(current->links) > flags->lenlink)
			flags->lenlink = ft_intlen(current->links);
		current->name = sd->d_name;
		current->next = malloc(sizeof(node_t));
		current = current->next;
	}
	//ft_ls_sort(files, flags);
	current->next = NULL;
	ft_print_list(files, flags);
	free(details);
}
