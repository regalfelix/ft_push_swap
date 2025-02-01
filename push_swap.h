/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:03:56 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/01 03:55:47 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_atol(const char *nptr);
// standalone atol();

int		list_len(t_stack *stk);
void	print_list(t_stack *stk);
void	print_arr(int *arr, int size);
t_stack	*create_node(int content);
t_stack	*create_stk(char **arr);
//list_manipulation.c

void	*free_the_list(t_stack **lst);
void	split_free(char **arr);
void	mis_input(t_stack **stk_a, t_stack **stk_b, char **arr, int status);
//free_my_mans.c

void	indexing(t_stack **stk, int *arr);
//indexing.c

void	swap(t_stack **stk, char *str);
void	push(t_stack **stk_from, t_stack **stk_to, char *str);
void	rotate(t_stack **stk, char *str);
void	reverse_rotate(t_stack **stk, char *str);
//movers.c

void	radix(t_stack *stk_a, t_stack *stk_b);
//radix.c

void	low_sort(t_stack **stk_a, t_stack **stk_b);
//low_sort.c
#endif
