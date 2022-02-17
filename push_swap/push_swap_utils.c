/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:09:57 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/17 14:37:08 by ullorent         ###   ########.fr       */
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
	int	chunk;

	i = 0;
	if (!head)
		return (0);
	array = malloc(ft_lstsize(head) * sizeof(int));
	if (!array)
		return (0);
	chunk = head->chunk;
	while (head != NULL)
	{
		if (head->chunk != chunk)
			break ;
		array[i] = (int)head->content;
		head = head->next;
		i++;
	}
	return (ft_quicksort(array, i));
}

int	ft_checkpivlim(t_list **head, int pivot, int boo)
{
	t_list	*temp;

	temp = *head;
	if (boo == 0)
	{
		while (temp != NULL)
		{
			if ((int)temp->content < pivot)
				return (1);
			temp = temp->next;
		}
	}
	else if (boo == 1)
	{
		while (temp != NULL)
		{
			if ((int)temp->content > pivot)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

int	ft_chunksize(t_list *head)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = head->chunk;
	while (head != NULL)
	{
		if (head->chunk != chunk)
			break ;
		head = head->next;
		i++;
	}
	return (i);
}
