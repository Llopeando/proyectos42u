/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:09:57 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/15 18:26:07 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_psw(size_t content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = (void *)content;
	node->next = NULL;
	return (node);
}

void	ft_errormsg(void)
{
	write(1, "Error\n", 6);
	write(1, "Check the list that you have introduced\n", 40);
	exit (1);
}

int	ft_getpivot(t_list *head)
{
	t_list	*for_middlelist;
	t_list	*for_endlist;
	int		pivot;

	for_middlelist = head;
	for_endlist = head;
	pivot = 0;
	if (head != NULL)
	{
		//ordenar todo
		//if (ft_isinorder(head))
		//else
		//32
		while (for_endlist != NULL && for_endlist->next != NULL)
		{
			for_endlist = for_endlist->next->next;
			for_middlelist = for_middlelist->next;
		}
		pivot = (int)for_middlelist->content;
	}
	return (pivot);
}
