/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/09/06 13:47:42 by enikel           ###   ########.fr       */
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
	int		lenbyte;
	int		lenlink;
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

int		ft_isflag(t_ls_flags *flags);
void	ft_ls_direct(t_ls_flags *flags, char *dirname, int argc);
void	ft_ls_finit(t_ls_flags *flags);
int		ft_ls_isfile(char *dirname);
int		ft_ls_exit(int err, char *var);
void	ft_ls_l(node_t *current, t_ls_flags *flags);
void	ft_ls_recursive(t_ls_flags *flags, char *path);
void	ft_ls_sort(node_t *files, t_ls_flags *flags);
void	ft_ls_tolist(DIR *dir, node_t *files, t_ls_flags *flags);
// void	ft_ls_a(DIR *dir, struct dirent *sd);

#endif