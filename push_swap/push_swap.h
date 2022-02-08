/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:59 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/08 13:54:02 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* -- main functions -- */
void	ft_addnumbers(t_list **head_a, char **argv);

/* --- utils and other functions */
t_list	*ft_lstnew_psw(size_t content);

/* -- errors checker -- */
void	ft_errormsg(void);
int		ft_numcheck(char *argv);
void	ft_numcheck_norep(t_list **head_a);

/* -- commands functions -- */

#endif