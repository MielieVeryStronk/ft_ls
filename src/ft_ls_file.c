/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:09:30 by enikel            #+#    #+#             */
/*   Updated: 2018/09/19 08:37:11 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_ls_file(t_ls_fl *flags, char *filename)
{
	DIR		*dir;
	t_node	*files;

	files = NULL;
	dir = opendir(filename);
	if (dir == NULL)
		ft_ls_exit(2, filename);
	flags->file = 1;
	ft_ls_tolist(dir, files, flags, ft_ls_checkpath(filename));
	flags->file = 0;
}
