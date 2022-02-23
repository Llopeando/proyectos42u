/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:10 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/23 19:48:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bistwo(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	temp = *head_b;
	if (ft_chunksize(head_b) <= 2)
	{
		if (ft_chunksize(head_b) == 2
			&& (int)temp->content < (int)temp->next->content)
		{
			ft_sb(head_b, 1);
			ft_pa(head_a, head_b);
		}
		ft_pa(head_a, head_b);
	}
}

void	ft_sort_b(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	int		c;
	int		pivot;

	c = 0;
	temp = *head_b;
	pivot = ft_getpivot(*head_b);
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
	while (c)
	{
		ft_rrb(head_b, 1);
		c--;
	}
}

void	ft_sort_aistwo(t_list **head_a)
{
	t_list	*temp;

	temp = *head_a;
	if (ft_chunksize(head_a) == 2)
	{
		if ((int)temp->content > (int)temp->next->content)
			ft_sa(head_a, 1);
	}
}

void	ft_sort_arracheck(t_list **head_a, int c2, int i)
{
	t_list	*temp;

	temp = *head_a;
	while (c2 && i == 1)
	{
		ft_rra(head_a, 1);
		c2--;
	}
}

void	ft_sort_apb(t_list **head_a, t_list **head_b, t_list *temp, int chunk_b)
{
	temp->chunk = chunk_b;
	ft_pb(head_a, head_b);
}

void ft_prueba (t_list **head_a, t_list **head_b, int i, t_list *temp)
{
	int	pivot;
	int	c2;
	int	chunk_b;

	chunk_b = 1;
	c2 = 0;
	pivot = ft_getpivot(*head_a);
	while (ft_checkpivlim(head_a, pivot, 0))
	{
		temp = *head_a;
		if ((int)temp->content < pivot)
		{
			temp->chunk = chunk_b;
			ft_pb(head_a, head_b);
		}
		else
		{
			ft_ra(head_a, 1);
				c2++;
		}
		temp = *head_a;
	}
	chunk_b++;
	ft_sort_arracheck(head_a, c2, i);
}

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int		chunk_b;
	int		i;
	int		pivot;
	int		c2;
	t_list	*temp;

	chunk_b = 1;
	i = 0;
	while (!ft_isinorder(head_a) || *head_b)
	{
		temp = *head_a;
		while (ft_chunksize(head_a) > 2)
		{
			ft_prueba(head_a, head_b, i, temp);
		}
		ft_sort_aistwo(head_a);
		if (!*head_b)
			continue ;
		ft_sort_b(head_a, head_b);
		ft_sort_bistwo(head_a, head_b);
		i = 1;
	}
}

void	ft_sort_three(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if (!ft_isinorder(head))
	{
		if ((int)temp->content > (int)temp->next->next->content
			&& (int)temp->content > (int)temp->next->content)
			ft_ra(head, 1);
		else if ((int)temp->next->content > (int)temp->content
			&& (int)temp->next->content > (int)temp->next->next->content)
			ft_rra(head, 1);
		temp = *head;
		if ((int)temp->content > (int)temp->next->content)
			ft_sa(head, 1);
	}
}
