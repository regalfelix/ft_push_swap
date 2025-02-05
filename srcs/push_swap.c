/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:09:07 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/05 18:35:53 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Verifies the string input syntax
static int	fed_inspection(char **arr)
{
	int	j;
	int	i;
	int	len;

	i = 0;
	while (arr[i])
	{
		j = 0;
		len = ft_strlen(arr[i]);
		if ((arr[i][j] == '-' || arr[i][j] == '+') && j == 0)
			j++;
		while (arr[i][j] && arr[i][j] == '0')
			j++;
		len -= j;
		if (len > 11 && !(len == 11 && (arr[i][0] == '-' || arr[i][0] != '+')))
			return (0);
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]) || !arr[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Calls fed_inspection() to verify the argument for push_swap and returns the
// newly created stack A after taking values from the char **arr
static t_stack	*stack_it_up(char *s, int flag)
{
	t_stack	*tmp_stk;
	char	**arr;

	arr = ft_split(s, ' ');
	if (flag)
		free(s);
	if ((arr == NULL) || (fed_inspection(arr) == 0))
		mis_input(NULL, NULL, arr, 1);
	tmp_stk = create_stk(arr);
	if (tmp_stk == NULL)
		mis_input(&tmp_stk, NULL, arr, 1);
	split_free(arr);
	return (tmp_stk);
}

// "Indexes" all values in stack A and checks stack A size to call either
// radix() or low_sort() to perform push_swap
static void	sort(t_stack *stk_a, t_stack *stk_b)
{
	int	stk_size;
	int	*arr;

	stk_size = list_len(stk_a);
	arr = (int *)malloc(stk_size * sizeof(int));
	if (!arr)
		mis_input(&stk_a, &stk_b, NULL, 1);
	indexing(&stk_a, arr);
	free(arr);
	if (stk_size > 5)
		radix(stk_a, stk_b);
	if (stk_size <= 5)
		low_sort(&stk_a, &stk_b);
}

// This function is in case the input of push swap is through argv[n] instead
// of argv[1] only, turns all of the argv into a single string so ft_split can
// process it
static char	*cringe_input(char **av, int ac)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		if (!tmp)
			return (NULL);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	main(int ac, char **av)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	char	*str;
	int		flag;

	flag = 0;
	stk_b = NULL;
	if (ac < 2 || av[1][0] == '\0')
		return (0);
	else if (ac == 2)
		str = av[1];
	else
	{
		flag++;
		str = cringe_input(av, ac);
		if (!str)
			mis_input(&stk_a, &stk_b, NULL, 1);
	}
	stk_a = stack_it_up(str, flag);
	if (!stk_a)
		mis_input(&stk_a, NULL, NULL, 1);
	sort(stk_a, stk_b);
}
