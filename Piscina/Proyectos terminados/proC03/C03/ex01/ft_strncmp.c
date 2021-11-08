/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:33:20 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/23 18:38:34 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;
	int				d;

	c = 0;
	d = 0;
	while (!d && (s1[c] != '\0') && (s2[c] != '\0') && (c < n))
	{
		d = (unsigned char)s1[c] - (unsigned char)s2[c];
		c++;
	}
	if ((s1[c] == '\0' || s2[c] == '\0') && !d && (c < n))
		d = (unsigned char)s1[c] - (unsigned char)s2[c];
	return (d);
}
