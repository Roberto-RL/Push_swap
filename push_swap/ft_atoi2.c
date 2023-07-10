/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:30:49 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/22 18:17:13 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

static long	*ft_check(const char *s, long *z)
{
	if (s[z[0]] != '+' && s[z[0]] != '-' && z[2] == 0)
		if (!(s[z[0]] >= '0' && s[z[0]] <= '9') && z[2] == 0)
			if (ft_strchr(" \t\v\n\r\f", (s[z[0]])) == 0 && z[2] == 0)
			z[5] += 1;
	if (s[z[0]] >= '0' && s[z[0]] <= '9')
	{
		if (z[6] != 0)
			z[1] = z[1] * 10;
		z[1] = z[1] + s[z[0]] - 48;
		z[2] = 1;
		z[6] = 1;
	}
	else if (z[2] == 1)
		z[2] = 2;
	else if (s[z[0]] == '-')
	{
		z[3] += 1;
	}
	else if (s[z[0]] == '+')
		z[4] += 1;
	else if (ft_strchr(" \t\v\n\r\f", (s[z[0]])) != 0 && (z[3] > 0 || z[4] > 0))
		z[5] += 1;
	if (z[3] > 1 || z[4] > 1 || (z[3] > 0 && z[4] > 0))
		z[5] += 1;
	return (z);
}

int	ft_atoi2(const char *str, t_g_list *g_list)
{
	long	x [7];

	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	x[3] = 0;
	x[4] = 0;
	x[5] = 0;
	x[6] = 0;
	while (str[x[0]] && x[2] != 2)
	{
		*x = *ft_check(str, x);
		if (x[5] > 0 || x[1] > INT_MAX || x[1] < INT_MIN || x[2] == 2)
			g_list->berror = 1;
		x[0]++;
	}
	if (x[3] % 2 != 0)
		x[1] = x[1] * -1;
	if (x[0] == 1 && (x[3] > 0 || x[4] > 0 || x[5] > 0))
		g_list->berror = 1;
	return (x[1]);
}
