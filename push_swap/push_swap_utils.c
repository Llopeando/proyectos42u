/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:09:57 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/16 16:16:55 by ullorent         ###   ########.fr       */
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
	int	*array;
	int	i;

	i = 0;
	array = malloc((ft_lstsize(head) + 1) * sizeof(int));
	while (head != NULL)
	{
		array[i] = (int)head->content;
		head = head->next;
		i++;
	}
	return (ft_quicksort(array, ft_lstsize(head)));
}
