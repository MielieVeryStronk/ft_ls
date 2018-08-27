/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:53:09 by enikel            #+#    #+#             */
/*   Updated: 2018/07/09 11:30:48 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		ft_joinnewline(char **line, char *src)
{
	char	*nl;

	nl = ft_strchr(src, '\n');
	if (nl)
	{
		*nl = '\0';
		*line = ft_strdup(src);
		nl++;
		ft_memmove(src, nl, ft_strlen(nl) + 1);
		return (1);
	}
	if (!nl && ft_strlen(src) > 0)
	{
		*line = ft_strdup(src);
		src[0] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*remain[0];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	long int	rdret;

	if (!line || fd < 0 || read(fd, buff, 0) != 0)
		return (-1);
	if (!remain[fd])
		remain[fd] = ft_strnew(BUFF_SIZE + 1);
	while (!ft_strchr(remain[fd], '\n'))
	{
		if ((rdret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rdret == 0)
			return (ft_joinnewline(line, remain[fd]));
		buff[rdret] = '\0';
		temp = ft_strjoin(remain[fd], buff);
		ft_strdel(&remain[fd]);
		remain[fd] = temp;
	}
	return (ft_joinnewline(line, remain[fd]));
}
