/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:51:38 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/17 15:49:11 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	*src;

	if (s && fd)
	{
		i = 0;
		src = (char*)s;
		while (src[i])
		{
			write(fd, &src[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
