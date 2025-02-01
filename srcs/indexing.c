/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:49 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/01 23:33:26 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Slightly modified bubble_sort function to order the array
static int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (arr);
}

// Matches numbers to an index and returns the index
static int	find_index(int value, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (value == arr[i])
			break ;
		i++;
	}
	return (i);
}

// Simple function to check doubles after the array is ordered by checking if
// arr[N] = arr[N + 1]
static int	check_doubles(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// "Indexes" (puts a value on every number on the stack in order from 0 to n)
// so it can be sorted later by radix in an optimal way.
// It does this by putting the stacks numbers in an integer array and sorting
// them. In the process, doubles are also checked. When finished, each index
// variable in the stack struct is given a value according to where it sits
// on the integer array
void	indexing(t_stack **stk, int *arr)
{
	int		size;
	int		i;
	t_stack	*current;

	size = list_len(*stk);
	i = 0;
	current = *stk;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	arr = bubble_sort(arr, size);
	if (!check_doubles(arr, size))
	{
		free(arr);
		mis_input(stk, NULL, NULL, 1);
	}
	current = *stk;
	while (current)
	{
		current->index = find_index(current->value, arr, size);
		current = current->next;
	}
}
