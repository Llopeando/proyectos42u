/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:01:38 by ullorent          #+#    #+#             */
/*   Updated: 2021/09/16 12:56:31 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdlen(char *s, char c)
{
	int	wrd;
	int	boo;
	int	i;

	wrd = 0;
	boo = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && boo == 0)
		{
			wrd++;
			boo = 1;
		}
		else if (s[i] == c)
			boo = 0;
		i++;
	}
	return (wrd);
}

char	*ft_wrdcomplete(char **s, char c)
{
	char	*nstr;
	int		n;

	n = 0;
	while ((*s)[n] == c && (*s)[n] != '\0')
		n++;
	*s += n;
	n = 0;
	while ((*s)[n] != '\0' && (*s)[n] != c)
		n++;
	nstr = ft_substr(*s, 0, n);
	*s += n + 1;
	return (nstr);
}

void	ft_wrdfree(char ***temp)
{
	int	i;

	i = 0;
	while ((*temp)[i] != NULL)
	{
		free((*temp)[i]);
		i++;
	}
	free(*temp);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_wrdlen((char *)s, c);
	temp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!temp)
		return (NULL);
	temp[count] = NULL;
	while (s && count--)
	{
		temp[i] = ft_wrdcomplete((char **)&s, c);
		if (!temp[i])
		{
			ft_wrdfree(&temp);
			return (0);
		}
		i++;
	}
	return (temp);
}
