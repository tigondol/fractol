/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:48:32 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/17 15:35:35 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	if (s1 && s2 && n)
	{
		while ((tmp1[i] || tmp2[i]) && i < n)
		{
			if (tmp1[i] != tmp2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
