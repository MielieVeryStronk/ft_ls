/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_isdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:48:33 by enikel            #+#    #+#             */
/*   Updated: 2018/09/13 11:48:36 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_ls_isdir(char *name)
{
	struct stat s;

	if (stat(name, &s) == 0)
	{
		if (s.st_mode & S_IFDIR)
			return (1);
		else if (s.st_mode & S_IFREG)
			return (0);
		else
			return (0);
	}
	else
		return (0);
}