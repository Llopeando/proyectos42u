/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejercicio2-processes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:43:41 by ullorent          #+#    #+#             */
/*   Updated: 2022/03/15 15:13:43 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	x;
	int	pid;

	argc = 0;
	argv = NULL;
	pid = fork();
	printf("La PID del proceso es %d\n", pid);
	if (pid == 0)
		printf("\n[Estás en el proceso hijo del principal]\n");
	x = 2;
	if (pid == -1)
		return (1);
	//printf("La PID del proceso es %d\n", pid);
	if (pid != 0)
	{
		sleep(3);
		printf("\nPID = %d\n", pid);
		printf("Este es el proceso 'padre'\n");
	}
	//printf("La PID del proceso es %d\n", pid);
	if (pid == 0)
	{
		printf("\nPID = %d\n", pid);
		printf("Este es el proceso 'hijo'\n");
	}
	if (pid != 0)
	{
		printf("\n/* --- Esperamos a que finalice el proceso --- */\n");
		wait (NULL);
	}
	return (0);
}
