/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errorschk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:12:26 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/07 15:24:23 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numcheck(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	if (((argv[i] == '-' || argv[i] == '+') && argv[i + 1]
			&& (argv[i + 1] > '9' || argv[i + 1] < '0'))
		|| ((argv[i] > '9' || argv[i] < '0')
			&& (argv[i] != '+' && argv[i] != '-')))
		return (0);
	i++;
	while (argv[i])
	{
		if (argv[i] > '9' || argv[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_numcheck_norep(t_list **head_a)
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = *head_a;
	while (temp_1)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->content == temp_2->content)
				ft_errormsg();
			temp_2 = temp_1->next;
		}
		temp_1 = temp_1->next;
	}
}
