/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:16:02 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/17 15:41:00 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strfill(int size, char *dest, char *tmp1, char *tmp2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (tmp1[j])
		{
			dest[i] = tmp1[j];
			i++;
			j++;
		}
		j = 0;
		while (tmp2[j])
		{
			dest[i] = tmp2[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*dest;
	char	*tmp1;
	char	*tmp2;

	if (s1 && s2)
	{
		tmp1 = (char*)s1;
		tmp2 = (char*)s2;
		size = ft_strlen(tmp1) + ft_strlen(tmp2);
		if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		dest = ft_strfill(size, dest, tmp1, tmp2);
		return (dest);
	}
	return (NULL);
}
