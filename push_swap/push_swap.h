/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:59 by ullorent          #+#    #+#             */
/*   Updated: 2022/02/09 13:50:32 by ullorent         ###   ########.fr       */
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
void	ft_errormsg(void);

/* -- errors checker -- */
int		ft_numcheck(char *argv);
void	ft_numcheck_norep(t_list **head_a);
int		ft_isinorder(t_list **head_a);

/* -- commands functions -- */
void	ft_sa(t_list **head, int boo);
void	ft_sb(t_list **head, int boo);
void	ft_ss(t_list **head_a, t_list **head_b);
void	ft_pa(t_list **head_a, t_list **head_b);
void	ft_pb(t_list **head_a, t_list **head_b);
void	ft_ra(t_list **head_a, int boo);
void	ft_rb(t_list **head_b, int boo);
void	ft_rr(t_list **head_a, t_list **head_b);

#endif