/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:14:44 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/19 13:08:10 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)src;
	tmp2 = (char*)dest;
	i = 0;
	while (n--)
	{
		*tmp2++ = *tmp1++;
	}
	return (dest);
}
