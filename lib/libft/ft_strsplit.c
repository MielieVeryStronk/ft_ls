/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:51:37 by enikel            #+#    #+#             */
/*   Updated: 2018/07/09 12:15:50 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcnt(const char *str, char delim)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delim && (str[i + 1] == delim ||
			str[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	arr[ft_wrdcnt(s, c)] = NULL;
	while (s[i] != '\0' && k < ft_wrdcnt(s, c))
	{
		while (s[i] == c)
			j = (i++) + 1;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[k] = ft_strsub(s, i, (j - i));
		k++;
		i = j;
	}
	return (arr);
}
