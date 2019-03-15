/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:57:50 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/18 18:28:58 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	char	*dest;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1] == '\t')
		size--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		size--;
	if (size <= 0)
		size = 0;
	if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	s += i;
	i = -1;
	while (++i < size)
	{
		dest[i] = *s;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}
