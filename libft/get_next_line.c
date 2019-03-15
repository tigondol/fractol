/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <tigondol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:38 by tigondol          #+#    #+#             */
/*   Updated: 2018/10/08 11:15:34 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_len(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void		ft_sub(char **line, char **str)
{
	char	*s;

	s = NULL;
	*line = ft_strsub(*str, 0, ft_len(*str, '\n'));
	s = ft_strsub(*str, ft_len(*str, '\n') + 1,
			ft_strlen(&str[0][ft_len(*str, '\n')]));
	ft_strdel(str);
	*str = s;
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static	char	*str[2147483647];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	ret = 0;
	if (line == NULL || fd < 0 || BUFF_SIZE < 0
			|| read(fd, "", 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while (!(ft_strchr(str[fd], '\n')))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	if (ft_strlen(str[fd]) == 0)
		return (0);
	ft_sub(line, &str[fd]);
	return (1);
}
