/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/03 18:12:47 by ullorent         ###   ########.fr       */
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
	while (argv[i] != NULL)
	{
		if ((ft_numcheck(argv[i]) == 0))
			ft_errormsg();
		numbers = ft_atoi(argv[i]);
		ft_lstadd_back(head_a, ft_lstnew_psw(&numbers));
		printf("%d\n", numbers);
		i++;
	}
	printf("\n");
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
	if (argc < 2)
		exit (1);
	if (argc != 1 && argc != 2)
		ft_addnumbers(&head_a, argv + 1);
	else
		ft_addnumbers(&head_a, ft_split(argv[1], ' '));
	write(1, "OK\n", 3);
	return (0);
}
