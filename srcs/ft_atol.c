/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:56:58 by frey-gal          #+#    #+#             */
/*   Updated: 2025/02/05 19:01:32 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *nptr)
{
	long	n;
	long	flag;

	flag = 0;
	n = 0;
	while ((*nptr <= 13 && *nptr >= 9) || *nptr == 32)
		nptr++;
	if (ft_strncmp(nptr, "-9223372036854775808", 11) == 0)
		return (LLONG_MAX);
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		flag++;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n *= 10;
		n = n + (*nptr++ - '0');
	}
	if (flag)
		n = -n;
	return (n);
}
