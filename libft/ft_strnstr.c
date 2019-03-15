/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:09:37 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/16 19:36:08 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t s)
{
	size_t	i;
	int		j;
	size_t	k;

	i = -1;
	j = 0;
	if (!(str || to_find))
		return (NULL);
	while (str[++i] != '\0' && i < s)
	{
		if (str[i] == to_find[j])
		{
			k = i;
			while (to_find[j] == str[k] && k < s && str[i] && to_find[j])
			{
				k++;
				j++;
			}
		}
		if (to_find[j] == '\0')
			return ((char*)str + i);
		else
			j = 0;
	}
	return (0);
}
