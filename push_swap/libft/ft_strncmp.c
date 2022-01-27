/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:03:15 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/15 16:18:21 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (str1[count] != '\0' && str2[count] != '\0'
		&& count < n - 1 && str1[count] == str2[count])
		count++;
	return ((unsigned char) str1[count] - (unsigned char) str2[count]);
}
