/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:41:45 by tigondol          #+#    #+#             */
/*   Updated: 2018/09/12 18:00:25 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_fill(char **tab, char const *s, int y, char *splitcar)
{
	int		a;
	int		c;
	int		i;

	i = 0;
	while (s[i])
	{
		while (ft_charcmpstr(s[i], splitcar) != -1)
			i++;
		a = i;
		while ((ft_charcmpstr(s[i], splitcar) == -1) && s[i])
		{
			i++;
			if ((ft_charcmpstr(s[i], splitcar) != -1) || !s[i])
			{
				if (!(tab[y] = (char*)malloc(sizeof(char) * (i - a + 1))))
					return (0);
				c = 0;
				while (a < i)
					tab[y][c++] = s[a++];
				tab[y++][c] = '\0';
			}
		}
	}
	return (0);
}

char			**ft_split(char const *s, char *splitcar)
{
	char	**tab;
	int		wc;
	int		i;

	if (!(s))
		return (NULL);
	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		while (ft_charcmpstr(s[i], splitcar) != -1 && s[i])
			i++;
		while ((ft_charcmpstr(s[i], splitcar) == -1) && s[i])
		{
			i++;
			if ((ft_charcmpstr(s[i], splitcar) != -1) || !s[i])
				wc++;
		}
	}
	if (!(tab = (char **)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	tab[wc] = 0;
	ft_fill(tab, s, 0, splitcar);
	return (tab);
}
