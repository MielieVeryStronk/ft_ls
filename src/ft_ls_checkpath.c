/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_checkpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:59:16 by enikel            #+#    #+#             */
/*   Updated: 2018/09/18 15:16:59 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ft_ls_checkpath(char *path)
{
	char *new;
	char *temp;

	new = NULL;
	temp = NULL;
	if (path[0] != '.' && path[1] != '/')
	{
		new = ft_strjoin("./", path);
	}
	else if (new == NULL)
		new = ft_strdup(path);
	if (new[ft_strlen(new) - 1] != '/')
	{
		temp = new;
		new = ft_strjoin(temp, "/");
		if (temp)
			free(temp);
	}
	return (new);
}
