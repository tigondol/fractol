/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:07:39 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/17 14:16:24 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;
	char	*tmp;

	i = 0;
	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	tmp = (char*)str;
	while (size--)
	{
		tmp[i] = 0;
		i++;
	}
	tmp[i] = 0;
	return (str);
}
