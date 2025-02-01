/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <frey-gal@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:44:02 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/01 23:37:17 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Finds the position/index of the smallest number in the stack, so it can be
// rotated to the top
static int	min_pos(t_stack *stk)
{
	t_stack	*tmp;
	int		i;
	int		min;

	tmp = stk;
	min = tmp->index;
	while (tmp)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	tmp = stk;
	i = 0;
	while (tmp)
	{
		if (min == tmp->index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

// Sorts stacks of three, can be called by four and five to sort as well
static void	sort_three(t_stack **stk_a)
{
	int		a;
	int		b;
	int		c;

	a = (*stk_a)->index;
	b = (*stk_a)->next->index;
	c = (*stk_a)->next->next->index;
	if (a < b && b < c)
		return ;
	if (a < c && c < b)
	{
		reverse_rotate(stk_a, "rra");
		swap(stk_a, "sa");
	}
	if (b < a && a < c)
		swap(stk_a, "sa");
	if (c < a && a < b)
		reverse_rotate(stk_a, "rra");
	if (b < c && c < a)
		rotate(stk_a, "ra");
	if (c < b && b < a)
	{
		swap(stk_a, "sa");
		reverse_rotate(stk_a, "rra");
	}
}

// Sorts stacks of four by moving 1 to stack B and using sort_three()
static void	sort_four(t_stack **stk_a, t_stack **stk_b)
{
	int		pos;

	pos = min_pos(*stk_a);
	if (pos == 1)
		swap(stk_a, "sa");
	if (pos == 2)
	{
		reverse_rotate(stk_a, "rra");
		reverse_rotate(stk_a, "rra");
	}
	if (pos == 3)
		reverse_rotate(stk_a, "rra");
	push(stk_a, stk_b, "pb");
	sort_three(stk_a);
	push(stk_b, stk_a, "pa");
}

// Sorts stacks of five by pushing node to Stack B and calling sort_four()
static void	sort_five(t_stack **stk_a, t_stack **stk_b)
{
	int		pos;

	pos = min_pos(*stk_a);
	if (pos == 1)
		swap(stk_a, "sa");
	if (pos == 2)
	{
		rotate(stk_a, "ra");
		rotate(stk_a, "ra");
	}
	if (pos == 3)
	{
		reverse_rotate(stk_a, "rra");
		reverse_rotate(stk_a, "rra");
	}
	if (pos == 4)
		reverse_rotate(stk_a, "rra");
	push(stk_a, stk_b, "pb");
	sort_four(stk_a, stk_b);
	push(stk_b, stk_a, "pa");
}

// Main function to sort stacks of five and below, also has a loop to check if
// the check if the stack is sorted beforehand
void	low_sort(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*current;
	int		size;

	current = *stk_a;
	while (current)
	{
		if (current->next == NULL)
			mis_input(stk_a, NULL, NULL, 0);
		if (current->index > current->next->index)
			break ;
		current = current->next;
	}
	size = list_len(*stk_a);
	if (size == 2)
		swap(stk_a, "sa");
	if (size == 3)
		sort_three(stk_a);
	if (size == 4)
		sort_four(stk_a, stk_b);
	if (size == 5)
		sort_five(stk_a, stk_b);
	mis_input(stk_a, stk_b, NULL, 0);
}
