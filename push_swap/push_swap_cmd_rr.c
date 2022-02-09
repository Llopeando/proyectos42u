/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:02:20 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/09 14:31:18 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **head_a, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*head_a)
		return ;
	temp1 = *head_a;
	temp2 = *head_a;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(head_a, temp1);
	if (boo)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **head_b, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*head_b)
		return ;
	temp1 = *head_b;
	temp2 = *head_b;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (temp2->next != temp1)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(head_b, temp1);
	if (boo)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	ft_rra(head_a, 0);
	ft_rrb(head_b, 0);
	write(1, "rrr\n", 4);
}
