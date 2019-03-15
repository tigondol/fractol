/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:47:41 by tigondol          #+#    #+#             */
/*   Updated: 2018/09/19 11:12:38 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;
	char	*tmp;

	if (s && fd)
	{
		i = 0;
		tmp = (char*)s;
		while (tmp[i])
		{
			write(fd, &tmp[i], 1);
			i++;
		}
	}
}
