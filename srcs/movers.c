/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:22:33 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/01 03:57:50 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stk, char *str)
{
	t_stack	*a;
	t_stack	*b;

	if (!*stk || !(*stk)->next)
		return ;
	a = *stk;
	b = a->next;
	a->next = b->next;
	b->next = a;
	*stk = b;
	ft_printf("%s\n", str);
}

void	push(t_stack **stk_from, t_stack **stk_to, char *str)
{
	t_stack	*tmp;

	tmp = *stk_from;
	*stk_from = tmp->next;
	tmp->next = *stk_to;
	*stk_to = tmp;
	ft_printf("%s\n", str);
}

void	rotate(t_stack **stk, char *str)
{
	t_stack	*first;
	t_stack	*last;

	if (list_len(*stk) <= 1)
		return ;
	first = *stk;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	*stk = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("%s\n", str);
}

void	reverse_rotate(t_stack **stk, char *str)
{
	t_stack	*last;
	t_stack	*second_last;

	if (list_len(*stk) <= 1)
		return ;
	second_last = *stk;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stk;
	*stk = last;
	ft_printf("%s\n", str);
}
