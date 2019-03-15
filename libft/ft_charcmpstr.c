/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcmpstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:32:22 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/18 15:29:21 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_charcmpstr(char str, char *splitcar)
{
	int i;

	i = 0;
	while (splitcar[i])
	{
		if (str == splitcar[i])
			return (1);
		i++;
	}
	return (-1);
}