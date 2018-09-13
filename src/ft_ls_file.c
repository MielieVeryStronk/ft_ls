/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:09:30 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 12:50:17 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_file(t_ls_fl *flags, char *filename)
{
	char	*temp;
	char	*replace;
	DIR		*dir;
	t_node	*files;

	if (!(files = malloc(sizeof(t_node))))
		ft_ls_exit(3, NULL);
	flags->file = 1;
	temp = ft_strdup(filename);
	temp = ft_ls_checkpath(temp);
	temp[ft_strlen(temp) - 1] = '\0';
	replace = ft_strrchr(temp, '/');
	replace++;
	*replace = '\0';
	dir = opendir(temp);
	if (dir == NULL)
		ft_ls_exit(2, filename);
	ft_ls_tolist(dir, files, flags, ft_ls_checkpath(filename));
	flags->file = 0;
}