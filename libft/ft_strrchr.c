/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:37:09 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/14 14:29:45 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;

	l = ft_strlen(s) + 1;
	while (--l)
	{
		if (s[l] == (char)c)
			return ((char*)s + l);
	}
	if (s[l] == (char)c)
		return ((char*)s + l);
	return (NULL);
}
