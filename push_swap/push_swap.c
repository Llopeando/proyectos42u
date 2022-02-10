/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/10 12:24:06 by ullorent         ###   ########.fr       */
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

void	ft_imprimir(t_list *head_a, t_list *head_b)
{
	int	i;

	i = 1;
	printf("\n\n///////////////////////////////////////////////////\n\n");
	printf("    \t       A       \t       B       \n");
	printf("    \t|-------------|\t|---------------|\n");
	while (head_a || head_b)
	{
		if (head_b && !head_a)
			printf("%d   \t|             |\t| %11d   |\n",
				i, (int)head_b->content);
		else if (head_a && !head_b)
			printf("%d   \t| %11d |\t|               |\n",
				i, (int)head_a->content);
		else
			printf("%d   \t| %11d | %11d |\n",
				i, (int)head_a->content,
				(int)head_b->content);
		if (head_a != NULL)
			head_a = head_a->next;
		if (head_b != NULL)
			head_b = head_b->next;
		i++;
	}
	printf("    \t|-------------|\t|---------------|\n");
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
		exit (1);
	ft_sa(&head_a, 1);
	ft_imprimir(head_a, head_b);
	printf("\n----------------------------------------------------\n");
	write(1, "\n", 1);
	write(1, "OK\n", 3);
	return (0);
}
