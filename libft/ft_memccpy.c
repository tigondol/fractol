/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:43:30 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/11 15:22:58 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned	char	*tmp1;
	unsigned	char	*tmp2;

	tmp1 = (unsigned char*)src;
	tmp2 = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		tmp2[i] = tmp1[i];
		if (tmp1[i] == (unsigned char)c)
			return (tmp2 + i + 1);
		i++;
	}
	return (NULL);
}
