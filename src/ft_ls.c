/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:24:31 by enikel            #+#    #+#             */
/*   Updated: 2018/08/21 13:23:46 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <stdio.h>

int     main(/*int argc, char **argv*/void)
{
	DIR             *dir;
	struct dirent   *sd;
	//struct stat		info;

	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		ft_printf("%s\n", sd->d_name);
	}
	return (0);
}