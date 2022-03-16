/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio3-resultado.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:41:30 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/16 18:25:48 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void	*ft_routine(int boo)
{
	int	mail;
	int	*result;

	mail = 0;
	mail = mail + 4;
	result = malloc(sizeof(int));
	*result = mail;
	printf("'Mail' en la función 'ft_routine' = %d\n", mail);
	if (boo == 0)
	{
		printf("Valor de memoria en la función principal = %p\n", result);
		*result += 1;
	}
	if (boo == 1)
		printf("Valor de memoria en la función secundaria = %p\n", result);
	write(1, "\n", 1);
	free(result);
	return ((void *)result);
}

int	main(void)
{
	pthread_t	p1;
	pthread_t	p2;
	int			*result;
	int			*result2;

	pthread_create(&p1, NULL, (void *)ft_routine, (void *)0);
	pthread_create(&p2, NULL, (void *)ft_routine, (void *)1);
	pthread_join(p1, (void **)&result);
	pthread_join(p2, (void **)&result2);
	printf("Resultado = %d\n",*result + *result2);
	printf("Valor de memoria final (principal) = %p\n", result);
	printf("Valor de memoria final (secundaria) = %p\n", result2);
	return (0);
}
