/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:33:36 by enikel            #+#    #+#             */
/*   Updated: 2018/08/31 13:42:58 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_list(node_t *list, t_ls_flags *flags, int longest)
{
	node_t *current;

	current = list;
    while (current != NULL)
	{
		if (current->name && flags->a > 0)
		{
			if (flags->l > 0)
				ft_ls_l(current, longest);
        	ft_printf("%s", current->name);
			ft_printf("\n");
		}
		else if (current->name && flags->a == 0 && current->name[0] != '.')
		{
			if (flags->l > 0)
				ft_ls_l(current, longest);
        	ft_printf("%s", current->name);
			ft_printf("\n");
		}
        current = current->next;
	}
}

void	ft_ls_tolist(DIR *dir, node_t *files, t_ls_flags *flags)
{
	node_t *current;
	struct dirent	*sd;
	struct stat		*details;
	struct passwd	*pwd;
	struct group	*grp;
	int				longest;

	current = files;
	longest = 0;
	details = malloc(sizeof(struct stat));
	while ((sd = readdir(dir)) != NULL)
	{
		stat(sd->d_name, details);
		current->mode = details->st_mode;
		current->links = details->st_nlink;
		pwd = getpwuid(details->st_uid);
		current->owner = pwd->pw_name;
		grp = getgrgid(details->st_gid);
		current->group = grp->gr_name;
		current->bytes = details->st_size;
		if (ft_intlen(current->bytes) > longest)
			longest = ft_intlen(current->bytes);
		current->date = ft_strdup(ctime(&details->st_ctime));
		current->name = sd->d_name;
		current->next = malloc(sizeof(node_t));
		current = current->next;
	}
	ft_ls_sort(files, flags);
	current->next = NULL;
	ft_print_list(files, flags, longest);
}