/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:10 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/15 16:50:52 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int		pivot;
	int		chunk_b;
	int		c;
	t_list	*temp;

	chunk_b = 1;
	temp = *head_a;
	while (!ft_isinorder(head_a) && !*head_b)
	{
		while (ft_lstsize(temp) > 2)
		{
			pivot = ft_getpivot(*head_a);
			while (temp != NULL)
			{
				if ((int)temp->content < pivot)
				{
					temp->chunk = chunk_b;
					ft_pb(head_a, head_b);
				}
				else
					ft_ra(head_a, 1);
				temp = temp->next;
			}
			chunk_b++;
		}
		if (ft_lstsize(*head_a) < 2 && !ft_isinorder(head_a))
			ft_sa(head_a, 1);
		pivot = ft_getpivot(*head_b);
		c = 0;
		while (temp != NULL)
		{
			if ((int)temp->content > pivot)
				ft_pa(head_a, head_b);
			else
			{
				ft_rb(head_b, 1);
				c++;
			}
			temp = temp->next;
		}
		while (c)
		{
			ft_rrb(head_b, 1);
			c--;
		}
	}
}
