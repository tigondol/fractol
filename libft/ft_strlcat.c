/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:41:42 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/11 17:23:04 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < dlen)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < size)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
