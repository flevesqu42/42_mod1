/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_backadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:12:01 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/12/14 17:29:37 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_backadd(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}
