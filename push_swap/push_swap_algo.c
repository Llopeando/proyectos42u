/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:10 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/22 20:21:11 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int		pivot;
	int		chunk_b;
	int		c;
	int		c2;
	int		i;
	t_list	*temp;

	chunk_b = 1;
	i = 0;
	while (!ft_isinorder(head_a) || *head_b)
	{
		//printf("hello4\n");
		//printf("isinorder = %d\n", ft_isinorder(head_a));
		temp = *head_a;
		c2 = 0;
		while (ft_chunksize(head_a) > 2)
		{
			//printf("coñe\n");
			pivot = ft_getpivot(*head_a);
			while (ft_checkpivlim(head_a, pivot, 0))
			{
				if ((int)temp->content < pivot)
				{
					temp->chunk = chunk_b;
					ft_pb(head_a, head_b);
				}
				else
				{
					ft_ra(head_a, 1);
					if (i == 1)
						c2++;
				}
				temp = *head_a;
			}
			chunk_b++;
			temp = *head_a;
			while (c2 && i == 1)
			{
				ft_rra(head_a, 1);
				c2--;
			}
			//printf("ft_chunksize = %d\n", ft_chunksize(head_a));
			//ft_imprimir(*head_a, *head_b);
		}
		temp = *head_a;
		if (ft_chunksize(head_a) == 2)
		{
			if ((int)temp->content > (int)temp->next->content)
				ft_sa(head_a, 1);
		}
		if (!*head_b)
			continue ;
		pivot = ft_getpivot(*head_b);
		c = 0;
		temp = *head_b;
		while (ft_checkpivlim(head_b, pivot, 1))
		{
			if ((int)temp->content > pivot)
				ft_pa(head_a, head_b);
			else
			{
				ft_rb(head_b, 1);
				c++;
			}
			temp = *head_b;
		}
		//ft_imprimir(*head_a, *head_b);
		while (c)
		{
			ft_rrb(head_b, 1);
			c--;
		}
		temp = *head_b;
		if (ft_chunksize(head_b) <= 2)
		{
			if (ft_chunksize(head_b) == 2
				&& (int)temp->content > (int)temp->next->content
				&& !((int)temp->content < 0 && (int)temp->next->content < 0))
				ft_sb(head_b, 1);
			else if (ft_chunksize(head_b) == 2
				&& (int)temp->content > (int)temp->next->content
				&& (int)temp->content > 0 && (int)temp->next->content > 0)
				ft_sb(head_b, 1);
			else if (ft_chunksize(head_b) == 2
				&& (int)temp->content < (int)temp->next->content
				&& (int)temp->content < 0 && (int)temp->next->content < 0)
				ft_sb(head_b, 1);
			if (ft_chunksize(head_b) == 2)
				ft_pa(head_a, head_b);
			ft_pa(head_a, head_b);
		}
		i = 1;
		//ft_imprimir(*head_a, *head_b);
	}
}

void	ft_sort_three(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if (!ft_isinorder(head))
	{
		if (temp->content < temp->next->next->content)
			ft_ra(head, 1);
		else
			ft_sa(head, 1);
	}
}
