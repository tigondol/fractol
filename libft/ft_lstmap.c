/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:12:13 by tigondol          #+#    #+#             */
/*   Updated: 2018/04/20 13:12:15 by tigondol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *new;
	t_list *tmp;
	t_list *nextone;

	if (!(lst || f))
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(nextone = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new->next = nextone;
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
