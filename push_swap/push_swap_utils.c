/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:09:57 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/01 16:37:21 by ullorent         ###   ########.fr       */
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

int	ft_atoi_psw(const char *str)
{
	unsigned int		c;
	int					j;
	unsigned long int	lint;

	c = 0;
	j = 1;
	lint = 0;
	while ((str[c] == ' ') || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			j = -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0')
	{
		lint = (lint * 10) + (str[c] - '0');
		c++;
	}
	if ((lint > 2147483648 && j == -1) || (lint > 2147483647 && j == 1))
		ft_errormsg();
	return (lint * j);
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

int	ft_chunksize(t_list **head)
{
	int		i;
	int		chunk;
	t_list	*temp;

	i = 0;
	temp = *head;
	chunk = temp->chunk;
	while (temp != NULL && temp->chunk == chunk)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
