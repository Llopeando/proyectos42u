/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/23 15:53:51 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addnumbers(t_list **head_a, char **argv)
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
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2 || *argv[1] == '\0')
		exit (1);
	if (argc != 1 && argc != 2)
		ft_addnumbers(&head_a, argv + 1);
	else
		ft_addnumbers(&head_a, ft_split(argv[1], ' '));
	ft_numcheck_norep(&head_a);
	if (ft_isinorder(&head_a))
		exit(1);
	if (ft_chunksize(&head_a) == 3)
	{
		ft_sort_three(&head_a);
		exit (1);
	}
	ft_sort(&head_a, &head_b);
	return (0);
}
