/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/01 17:52:44 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addnumbers(t_list **head_a, char **argv, int boo)
{
	int		numbers;
	int		i;
	int		c;
	t_list	*temp;

	i = 0;
	c = 0;
	if (!argv)
		ft_errormsg();
	while (argv[i] != NULL)
	{
		if (!ft_numcheck(argv[i]))
			ft_errormsg();
		numbers = ft_atoi_psw(argv[i]);
		ft_lstadd_back(head_a, ft_lstnew_psw(numbers));
		i++;
	}
	temp = *head_a;
	while (temp != NULL)
	{
		temp->chunk = 0;
		temp = temp->next;
	}
	if (boo == 1)
		ft_freemem(temp, argv, 1);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		exit (0);
	if (argc != 1 && argc != 2)
		ft_addnumbers(&head_a, argv + 1, 0);
	else
		ft_addnumbers(&head_a, ft_split(argv[1], ' '), 1);
	ft_numcheck_norep(&head_a);
	if (ft_isinorder(&head_a))
		exit (1);
	if (ft_chunksize(&head_a) == 3)
	{
		ft_sort_three(&head_a);
		exit (1);
	}
	ft_sort(&head_a, &head_b);
	ft_freemem(head_a, argv, 0);
	ft_freemem(head_b, argv, 0);
	return (0);
}
