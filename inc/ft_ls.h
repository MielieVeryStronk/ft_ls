/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/08/29 14:12:50 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define LS_OPTIONS "rRalt"

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct	s_ls_flags
{
	int		l;
	int		dr;
	int		a;
	int		r;
	int		t;
}				t_ls_flags;

void	ft_ls_finit(t_ls_flags *flags);

#endif