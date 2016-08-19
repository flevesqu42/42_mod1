/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:22:59 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/29 17:21:45 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (lst || f)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (new == NULL)
			return (NULL);
		new = f(new);
		temp = new;
		lst = lst->next;
		while (lst)
		{
			new->next = ft_lstnew(lst->content, lst->content_size);
			if (new->next == NULL)
				return (NULL);
			new->next = f(new->next);
			new = new->next;
			lst = lst->next;
		}
		return (temp);
	}
	return (NULL);
}
