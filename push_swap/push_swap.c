/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/08 14:19:16 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head, int boo)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *head;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*head = temp2;
	if (boo)
		printf("sa\n");
}

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
		if (!ft_numcheck(argv[i]))
			ft_errormsg();
		numbers = ft_atoi(argv[i]);
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

void	ft_super_print(t_list *head_a, t_list *head_b)
{
	printf("head_a: ");
	while (head_a != NULL)
	{
		printf("%d ", (int)head_a->content);
		head_a = head_a->next;
	}
	printf("\n");
	printf("head_b: ");
	while (head_b != NULL)
	{
		printf("%d ", (int)head_b->content);
		head_b = head_b->next;
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
	ft_super_print(head_a, head_b);
	printf("\n");
	ft_sa(&head_a, 1);
	ft_super_print(head_a, head_b);
	write(1, "OK\n", 3);
	return (0);
}
