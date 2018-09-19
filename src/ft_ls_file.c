/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:09:30 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 15:53:02 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_file_exists(char *filename)
{
	struct stat	buff;

	return(stat(filename, &buff) == 0);
}

void	ft_ls_file(t_ls_fl *flags, char *filename)
{
	DIR		*dir;
	t_node	*files;
	char	*temp;
	char	*new;
	char	*pos;

	if (!(files = ft_memalloc(sizeof(t_node))))
		ft_ls_exit(3, NULL);
	temp = ft_ls_checkpath(filename);
	new = ft_ls_checkpath(filename);
	temp[ft_strlen(temp) - 1] = '\0';
	pos = ft_strrchr(temp, '/');
	*++pos = '\0';
	dir = opendir(temp);
	if (dir == NULL)
		ft_ls_exit(2, filename);
	flags->file = 1;
	if (ft_file_exists(filename))
		ft_ls_tolist(dir, files, flags, new);
	else
		ft_ls_exit(2, filename);
	flags->file = 0;
	ft_ls_freelist(files);
	if (temp)
		free(temp);
	if (new)
		free(new);
	free(dir->__dd_buf);
	if (dir)
		free(dir);
}
