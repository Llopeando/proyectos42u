/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:38:47 by ullorent          #+#    #+#             */
/*   Updated: 2021/06/24 11:23:00 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	while ((src[d] != '\0') && (0 < nb))
	{
		dest[c] = (unsigned char)src[d];
		c++;
		d++;
		nb--;
	}
	dest[c] = '\0';
	return (dest);
}
