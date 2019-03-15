/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgondolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:48:00 by tgondolo          #+#    #+#             */
/*   Updated: 2018/04/10 15:45:43 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	negative(int *n, int *signe)
{
	if (*n < 0)
	{
		*signe = 1;
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	int		res;
	int		signe;
	char	*dest;
	int		cmpt;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cmpt = 2;
	res = n;
	signe = 0;
	negative(&n, &signe);
	while (res /= 10)
		cmpt++;
	cmpt = cmpt + signe;
	if (!(dest = (char*)malloc(sizeof(char) * cmpt)))
		return (NULL);
	dest[--cmpt] = '\0';
	while (cmpt--)
	{
		dest[cmpt] = n % 10 + '0';
		n = n / 10;
	}
	if (signe != 0)
		dest[0] = '-';
	return (dest);
}
