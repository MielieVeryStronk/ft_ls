/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:31:03 by enikel            #+#    #+#             */
/*   Updated: 2018/06/13 12:44:11 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		ph;

	a = 0;
	ph = 0;
	if (haystack == needle || !needle[a])
		return ((char *)haystack);
	if (!haystack[a])
		return (NULL);
	while (haystack[ph + a] != '\0')
	{
		if (needle[a] == haystack[ph + a])
			a++;
		if (needle[a] == '\0')
			return ((char *)&haystack[ph]);
		if (needle[a] != haystack[a + ph] && needle[a] != '\0')
		{
			ph++;
			a = 0;
		}
	}
	return (NULL);
}
