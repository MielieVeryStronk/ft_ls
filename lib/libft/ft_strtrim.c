/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 09:58:20 by enikel            #+#    #+#             */
/*   Updated: 2018/07/09 12:07:14 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		lim;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	lim = ft_strlen(s) - 1;
	while (s[lim] == ' ' || s[lim] == '\n' || s[lim] == '\t')
		lim--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (lim < i)
		str = malloc(1);
	else
		str = malloc((lim - i) + 2);
	if (!str)
		return (NULL);
	while (i <= lim)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
