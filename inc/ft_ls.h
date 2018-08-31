/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/08/31 13:44:06 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define LS_OPTIONS "rRalt"

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct	s_ls_flags
{
	int		l;
	int		dr;
	int		a;
	int		r;
	int		t;
}				t_ls_flags;

typedef struct node
{
    char		*name;
	unsigned	mode;
	int			links;
	char		*owner;
	char		*group;
	char		*date;
	long long	bytes;
    struct node *next;
} 				node_t;

void	ft_ls_finit(t_ls_flags *flags);
int		ft_ls_exit(int err, char *var);
void	ft_ls_l(node_t *current, int longest);
void	ft_ls_sort(node_t *files, t_ls_flags *flags);
void	ft_ls_tolist(DIR *dir, node_t *files, t_ls_flags *flags);
// void	ft_ls_a(DIR *dir, struct dirent *sd);

#endif