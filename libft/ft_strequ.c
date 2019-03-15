/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:38:54 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/17 15:35:07 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	if (s1 && s2)
	{
		while (tmp1[i] || tmp2[i])
		{
			if (tmp1[i] != tmp2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
