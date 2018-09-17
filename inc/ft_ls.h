/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:14:06 by enikel            #+#    #+#             */
/*   Updated: 2018/09/17 09:42:28 by enikel           ###   ########.fr       */
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

typedef struct	s_ls_fl
{
	int			l;
	int			dr;
	int			a;
	int			r;
	int			t;
	int			file;
	int			lenbyte;
	int			lenlink;
}				t_ls_fl;

typedef struct	s_no
{
	char		*name;
	unsigned	mode;
	int			links;
	char		*owner;
	char		*group;
	char		*date;
	unsigned	cdate;
	long long	bytes;
	int			block;
	struct s_no	*next;
	struct s_no	*prev;
}				t_node;

int				ft_isflag(t_ls_fl *flags);
int				ft_ls_blocksize(t_node *current);
char			*ft_ls_checkpath(char *path);
void			ft_ls_direct(t_ls_fl *flags, char *dirname, int argc);
void			ft_ls_file(t_ls_fl *flags, char *filename);
void			ft_ls_finit(t_ls_fl *flags);
void			ft_ls_freelist(t_node *list);
int				ft_ls_isdir(char *name);
int				ft_ls_exit(int err, char *var);
void			ft_ls_l(t_node *current, t_ls_fl *flags);
void			ft_print_list(t_node *current, t_ls_fl *flags);
void			ft_ls_recursive(t_ls_fl *flags, char *path);
void			ft_ls_sort(t_node **current, t_ls_fl *flags);
void			ft_ls_sort_name(t_node **current);
void			ft_ls_sort_date(t_node **current);
void			ft_ls_sort_rdate(t_node **current);
void			ft_ls_sort_rev(t_node **current);
void			ft_ls_sort_switch(t_node **start, t_node *node);
void			ft_ls_specific(t_node *list, t_ls_fl *flags, char *name);
void			ft_ls_tolist(DIR *dir, t_node *file, t_ls_fl *fl, char *pa);

#endif
