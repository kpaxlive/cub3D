/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:47:20 by fayan             #+#    #+#             */
/*   Updated: 2022/02/03 17:47:37 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!del || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp2 = (tmp)->next;
		(*del)((tmp)->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
