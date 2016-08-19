/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:32:29 by ocarta-l          #+#    #+#             */
/*   Updated: 2015/11/28 21:00:30 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *lst;

	lst = *alst;
	del(lst->content, lst->content_size);
	free(lst);
	lst->content = NULL;
	lst->content_size = 0;
	lst = NULL;
	*alst = lst;
}
