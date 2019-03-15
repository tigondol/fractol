/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:01:01 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/14 15:07:02 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)src;
	tmp2 = (char*)dest;
	if (dest > src)
	{
		while (n--)
		{
			tmp2[n] = tmp1[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
