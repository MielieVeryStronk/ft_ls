/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:14:27 by enikel            #+#    #+#             */
/*   Updated: 2018/08/27 14:14:12 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# define PRINT_SPEC "sSpdDioOuUxXcC\%\0"
# define VALID_MOD_SPEC "scdDioOuUxX"
# define PRINT_LMODS "lhjz"
# define PRINT_FLAGS "-+#0 "
# define ULONG_MAX	4294967296

# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_arg
{
	int		width;
	int		justify;
	int		z_fill;
	int		precision;
	int		hash;
	int		h;
	int		j;
	int		l;
	int		z;
	int		sign;
	int		spec;
	int		ret;
	int		index;
	int		search;
}				t_arg;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_intlen(long long int n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(long long int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
void        ft_putwchar(wchar_t  c);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnew(size_t size);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrev(char *str);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
int			ft_tolower(int c);
int			ft_toupper(int c);

int			get_next_line(const int fd, char **line);

char		*ft_itoa_base(long int n, int base);
char		*ft_ulltoa_base(uintmax_t n, int base);
void		ft_putnbr_base(long int n, int base);
char		*ft_str_capitalize(char *str);

void			ft_arginit(t_arg *arg);
void			ft_arg_reset_mod(t_arg *arg);
int				ft_arghandle(const char *format, va_list valist);
t_arg			*ft_handle_h(t_arg *arg, va_list valist);
t_arg			*ft_handle_hh(t_arg *arg, va_list valist);
t_arg			*ft_handle_l(t_arg *arg, va_list valist);
t_arg			*ft_handle_ll(t_arg *arg, va_list valist);
t_arg			*ft_handle_j(t_arg *arg, va_list valist);
t_arg			*ft_handle_z(t_arg *arg, va_list valist);
t_arg			*ft_hspec(const char *format, t_arg *arg, va_list valist);
int				ft_printf(const char *format, ...);
int				ft_print_c(unsigned char c);
int				ft_print_d(int num);
int				ft_print_ld(long int num);
int				ft_print_p(long p);
int				ft_print_s(char *str);
int				ft_print_o(unsigned int o);
int				ft_print_lo(unsigned long o);
int				ft_print_u(unsigned int u);
int				ft_print_lu(unsigned long long u);
int				ft_print_wchar(wint_t c);
int				ft_print_wstr(wint_t *c);
int				ft_print_x(unsigned long long x);
int				ft_print_x_upper(unsigned long long x);

#endif
