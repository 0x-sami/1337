/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalama <ysalama@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 01:54:08 by ysalama           #+#    #+#             */
/*   Updated: 2026/10/27 03:34:31 by ysalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst)
		return (NULL);
	struct s_list	*new_head;
	struct s_list	*current_original;
	struct s_list	*current_new;
	
	new_head = ft_lstnew(lst->content);
	current_original = lst->next;
	current_new = new_head;

	while (current_original)
	{
		current_new->next = ft_lstnew(current_original->content);
		current_new->content = f(current_new->content);
		current_new = current_new->next;
		current_original = current_original->next;
	}
	return (new_head);
}
