/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:07:04 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/02/19 06:53:19 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void*), void (*del)(void*))
{
	t_lst	*new_lst;
	t_lst	*test;

	new_lst = NULL;
	test = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		test = ft_lstnew((f)(lst->content));
		if (!test)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&new_lst, test);
		lst = lst->next;
	}
	return (new_lst);
}
