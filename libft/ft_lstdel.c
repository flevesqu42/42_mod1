/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:55:38 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/28 22:36:41 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	int		i;
	t_list	*lst;
	t_list	*temp;

	lst = *alst;
	i = 0;
	while (lst)
	{
		temp = lst;
		ft_lstdelone(&lst, del);
		lst = temp;
		lst = lst->next;
	}
	lst = NULL;
	*alst = lst;
}
