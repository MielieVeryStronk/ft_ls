/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:22:49 by enikel            #+#    #+#             */
/*   Updated: 2018/09/11 16:14:28 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_capitalize(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(str);
	while (temp[i] != '\0')
	{
		if (ft_islower(temp[i]))
			temp[i] = ft_toupper(temp[i]);
		i++;
	}
	return (temp);
}
