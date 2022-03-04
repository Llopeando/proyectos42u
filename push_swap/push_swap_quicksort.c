/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:49:28 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/04 13:46:41 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		t;
	t_list	*temp;

	temp = NULL;
	t = *a;
	*a = *b;
	*b = t;
}

int	ft_quicksort(int *arr, int max)
{
	int	i;
	int	j;
	int	pivot;
	int	len;

	len = 0;
	if (!arr)
		return (0);
	while (len < max)
	{
		i = 0;
		j = 1;
		while (j < max)
		{
			if (arr[j] < arr[i])
				ft_swap(&arr[i], &arr[j]);
			j++;
			i++;
		}
		len++;
	}
	pivot = arr[max / 2];
	free (arr);
	return (pivot);
}

void	ft_sort_three(t_list **head)
{
	t_list	*temp;
	char	**argv;

	argv = NULL;
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
	ft_freemem(*head, argv, 0);
	exit (1);
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
