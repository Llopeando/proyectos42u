/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:10 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/01 17:35:18 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_heada_five(t_list **head_a, int pivot)
{
	t_list	*temp;

	temp = *head_a;
	if ((int)temp->content >= pivot)
		ft_ra(head_a, 1);
	temp = *head_a;
}

void	ft_sort_heada(t_list **head_a, t_list **head_b, int i, int chunk_b)
{
	int			pivot;
	int			c2;
	t_list		*temp;

	c2 = 0;
	pivot = ft_getpivot(*head_a);
	while (ft_checkpivlim(head_a, pivot, 0))
	{
		temp = *head_a;
		if ((int)temp->content < pivot)
		{
			temp->chunk = chunk_b;
			ft_pb(head_a, head_b);
			continue ;
		}
		temp = ft_lstlast(*head_a);
		if ((int)temp->content < pivot)
		{
			ft_rra(head_a, 1);
			continue ;
		}
		ft_sort_heada_five(head_a, pivot);
		c2++;
	}
	ft_sort_arracheck(head_a, c2, i);
}

void	ft_sort(t_list **head_a, t_list **head_b)
{
	static int	chunk_b;
	int			i;
	t_list		*temp;

	chunk_b = 1;
	i = 0;
	while (!ft_isinorder(head_a) || *head_b)
	{
		temp = *head_a;
		while (ft_chunksize(head_a) > 2)
		{
			ft_sort_heada(head_a, head_b, i, chunk_b);
			chunk_b++;
		}
		ft_sort_aistwo(head_a);
		if (!*head_b)
			continue ;
		ft_sort_b(head_a, head_b);
		ft_sort_bistwo(head_a, head_b);
		i = 1;
	}
}
