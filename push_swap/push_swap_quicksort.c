/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:49:28 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/16 16:16:58 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	ft_quicksort(int *arr, int max)
{
	int	i;
	int	j;
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
	if (len % 2 == 0)
		return (arr[max / 2 + 1]);
	return (arr[max / 2]);
}
