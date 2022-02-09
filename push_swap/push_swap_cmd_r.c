/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:30:05 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/09 15:14:27 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **head_a, int boo)
{
	t_list	*temp1;

	if (!*head_a)
		return ;
	temp1 = *head_a;
	if (temp1->next != NULL)
		*head_a = temp1->next;
	else
		*head_a = NULL;
	ft_lstadd_back(head_a, temp1);
	temp1->next = NULL;
	if (boo)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **head_b, int boo)
{
	t_list	*temp2;

	if (!*head_b)
		return ;
	temp2 = *head_b;
	if (temp2->next != NULL)
		*head_b = temp2->next;
	else
		*head_b = NULL;
	ft_lstadd_back(head_b, temp2);
	temp2->next = NULL;
	if (boo)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	ft_ra(head_a, 0);
	ft_rb(head_b, 0);
	write(1, "rr\n", 3);
}
