/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:56:59 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/09 20:18:18 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*ft_function(void)
{
	printf("Esta es una prueba de 'threads'\n");
	sleep(2);
	printf("La función ha vuelto ha ser llamada y ha acabado\n");
	return (0);
}

int	main(int argc, char **argv)
{
	//con esto, creamos el proceso
	pthread_t	t1;
	pthread_t	t2;

	argc = 1;
	argv = NULL;
	//con esto inicializamos el proceso (nombre del proceso, atributo del proceso, nombre de la función, parametro para la función)
	pthread_create(&t1, NULL, (void *)ft_function, NULL);
	pthread_create(&t2, NULL, (void *)ft_function, NULL);
	//tenemos que esperar que el proceso finalize la ejecución
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
