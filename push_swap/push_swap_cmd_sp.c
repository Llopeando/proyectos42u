/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_sp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:49 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/17 15:06:21 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (*head == NULL)
		return ;
	temp1 = *head;
	if (temp1->next != NULL)
	{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
		*head = temp2;
		if (boo == 1)
			write(1, "sa\n", 3);
	}
}

void	ft_sb(t_list **head, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (!*head)
		return ;
	temp1 = *head;
	if (!temp1->next)
		return ;
	else if (temp1 != NULL)
	{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
		*head = temp2;
		if (boo)
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*temp2;

	temp2 = NULL;
	if (!*head_b)
		return ;
	temp2 = *head_b;
	if (temp2->next != NULL)
		*head_b = temp2->next;
	else
		*head_b = NULL;
	ft_lstadd_front(head_a, temp2);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*temp1;

	temp1 = NULL;
	if (!*head_a)
		return ;
	temp1 = *head_a;
	if (temp1->next != NULL)
		*head_a = temp1->next;
	else
		*head_a = NULL;
	ft_lstadd_front(head_b, temp1);
	write(1, "pb\n", 3);
}
