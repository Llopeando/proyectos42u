/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:37:46 by ullorent          #+#    #+#             */
/*   Updated: 2022/01/25 19:49:30 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	node;
	/* t_node	elem2; */
	argc = 0;
	argv = NULL;
	node.data = 15; //elemento 1
	/* node.next = &elem2; //aqui pasamos al siguiente elemento */
	node.next = malloc(sizeof(node)); //esto sirve para saber el tamaño de la memoria del siguiente elemento
	/*elem2.data = 10; //elemento 2 */
	node.next->data = 10; //elemento 2 mediante uso de malloc
	/*elem2.next = NULL; //aqui acabaria la lista (ultimo elemento) */
	node.next->next = NULL; //aqui acabaria la lista con malloc (ultimo elemento) */
	printf("Elemento 1: %d\n", node.data);
	printf("Elemento 2: %d\n", node.next->data);
	printf("Elemento 2 (diferente): %d\n", node.next->data);
	free(node.next);
	return (0);
}
