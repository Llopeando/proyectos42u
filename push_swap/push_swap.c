/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:23:02 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/01 19:49:03 by ullorent         ###   ########.fr       */
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
			if ((int)(((argv[i][c] == '-' || argv[i][c] == '+')
				&& (argv[i][c + 1] <= '9' && argv[i][c + 1] >= '0'))))
				return (0);
			if ((int)((argv[i][c] >= ' ' && argv[i][c] <= '/') ||
			(argv[i][c] >= ':' && argv[i][c] <= '~')))
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

t_list	*ft_lstnew_psw(size_t *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	main(int argc, char **argv)
{
	t_node	*node;
	int		*numbers;
	int		i;

	i = 1;
	node = NULL;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	ft_numcheck((char **)argv);
	while (argv[i] != NULL)
		i++;
	numbers = malloc(sizeof(int) * i);
	i = 1;
	while (argv[i] != NULL)
	{
		numbers[i - 1] = ft_atoi(argv[i]);
		printf("%d ", numbers[i -1]);
		i++;
	}
	/*ft_addnumbers()
	// while (argv[i][c])
	// {
	// 	ft_lstadd_back(&node->data, ft_lstnew(ft_atoi(&argv[i][c])));
	// 	c++;
	} */
	write(1, "OK\n", 3);
	return (0);
}
