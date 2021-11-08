/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:24:02 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/24 12:13:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	c;
	int	d;

	c = 0;
	while (to_find[0] == '\0')
		return (str);
	while (str[c] != '\0')
	{
		d = 0;
		while ((str[c + d] == to_find[d]) && (to_find[d] != '\0'))
		{
			if (to_find[d + 1] == '\0')
				return (&str[c]);
			d++;
		}
		c++;
	}
	return (0);
}
