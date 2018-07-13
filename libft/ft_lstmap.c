/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:29:17 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 15:43:38 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cur;
	t_list	*last;

	cur = NULL;
	last = NULL;
	while (lst)
	{
		new = f(lst);
		new->next = NULL;
		if (cur == NULL)
			cur = new;
		if (last)
			last->next = new;
		last = new;
		lst = lst->next;
	}
	return (cur);
}
