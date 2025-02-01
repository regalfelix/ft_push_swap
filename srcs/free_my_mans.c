/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_my_mans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <frey-gal@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:28:21 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/01 23:44:16 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Frees the list node by node, returns NULL to save lines
void	*free_the_list(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
	return (NULL);
}

// Frees each element of the char **str
void	split_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Function that safely frees by checking for NULL before freeing, and uses
// exit(status) with error message
void	mis_input(t_stack **stk_a, t_stack **stk_b, char **arr, int status)
{
	if (stk_a)
		free_the_list(stk_a);
	if (stk_b)
		free_the_list(stk_b);
	split_free(arr);
	if (status == 1)
		ft_printf("Error\n");
	exit(status);
}
