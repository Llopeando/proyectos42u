/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:49 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/08 18:57:07 by ullorent         ###   ########.fr       */
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
			printf("sa\n");
	}
}

void	ft_sb(t_list **head, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (*head != NULL)
		temp1 = *head;
	else if (temp1 != NULL)
	{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
		*head = temp2;
		if (boo)
			printf("sb\n");
	}
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	printf("ss\n");
}
