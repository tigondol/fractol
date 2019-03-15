/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgondolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:14:04 by tgondolo          #+#    #+#             */
/*   Updated: 2018/04/17 15:24:37 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	diff;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && i < n - 1) && (s2[i] != '\0' && s1[i] == s2[i]))
		i++;
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (diff != 0)
		return (diff);
	return (0);
}
