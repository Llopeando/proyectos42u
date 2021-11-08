/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:30:23 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/23 12:38:48 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 'A') && (str[c] <= 'Z'))
			str[c] = str[c] + 32;
		while ((str[c] < '0') || (str[c] > '9' && str[c] < 'A')
			|| (str[c] > 'Z' && str[c] < 'a') || (str[c] > 'z'))
		{
			c++;
			if ((str[c] >= 'a') && (str[c] <= 'z'))
				str[c] = str[c] - 32;
		}
		if (c == 0)
		{
			if ((str[c] >= 'a') && (str[c] <= 'z'))
				str[c] = str[c] - 32;
			c++;
		}
		c++;
	}
	return (str);
}
