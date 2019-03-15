/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:09:33 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/14 13:49:31 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*test1;
	unsigned	char	*test2;

	test1 = (unsigned char*)s1;
	test2 = (unsigned char*)s2;
	if (s1 == s2)
		return (0);
	while (n--)
	{
		if (*test1 != *test2)
			return (*test1 - *test2);
		test1++;
		test2++;
	}
	return (0);
}
