/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:24:28 by irlozano          #+#    #+#             */
/*   Updated: 2023/10/10 15:44:25 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst->content);
	new = ft_lstnew(temp);
	if (new == NULL)
	{
		free(temp);
		ft_lstclear(&new, del);
		return (NULL);
	}
	new->next = ft_lstmap(lst->next, f, del);
	return (new);
}
