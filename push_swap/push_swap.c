/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/02 18:08:24 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numcheck(char **argv)
{
	int	c;
	int	i;

	c = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		c = 0;
		while (argv[i][c])
		{
			if ((((argv[i][c] == '-' || argv[i][c] == '+')
				&& (argv[i][c + 1] <= '9' && argv[i][c + 1] >= '0'))))
				return (0);
			if (!(argv[i][c] <= '9' && argv[i][c] >= '0')
				|| (argv[i][c + 1] == '-' || argv[i][c + 1] == '+'))
			{
				write(1, "Error\n", 6);
				write(1, "That character its not an int number.\n", 38);
				exit (1);
			}
			c++;
		}
		i++;
	}
	return (0);
}

t_list	*ft_lstnew_psw(int *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_addnumbers(t_list **head_a, char **argv)
{
	int		numbers;
	int		i;
	int		c;
	t_list	*temp;

	i = 1;
	c = 0;
	while (argv[i] != NULL)
		i++;
	i = 1;
	while (argv[i] != NULL)
	{
		numbers = ft_atoi(argv[i]);
		ft_lstadd_back(head_a, ft_lstnew_psw(&numbers));
		printf("%d ", numbers);
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
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	ft_numcheck((char **)argv);
	ft_addnumbers(&head_a, argv);
	write(1, "OK\n", 3);
	return (0);
}
