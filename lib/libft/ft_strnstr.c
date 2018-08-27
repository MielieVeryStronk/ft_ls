/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:26:13 by enikel            #+#    #+#             */
/*   Updated: 2018/06/14 11:41:13 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		a;
	size_t		ph;

	a = 0;
	ph = 0;
	if (needle == haystack || !needle[a])
		return ((char *)haystack);
	if (!haystack[a])
		return (NULL);
	while ((ph + a) < n && haystack[ph + a] != '\0')
	{
		while (needle[a] == haystack[ph + a] && (ph + a) < n
				&& needle[a] != '\0')
			a++;
		if (needle[a] == '\0')
			return ((char *)&haystack[ph]);
		a = 0;
		ph++;
	}
	return (NULL);
}
