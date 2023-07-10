/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:07 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:22:35 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search_number_above(t_g_list *g_list)
{
	changenode (g_list, 0);
	g_list->mode = 1;
	changenode (g_list, 3);
	if (g_list->a_list != 0)
		g_list->auxindex1 = g_list->a_list->index;
	g_list->mode = 0;
	changenode (g_list, 0);
	changenode (g_list, 3);
}

void	ft_search_number_below(t_g_list *g_list)
{
	g_list->mode = 1;
	changenode (g_list, 0);
	if (g_list->a_list != 0)
		g_list->auxindex2 = g_list->a_list->index;
}

/**
 * This function finds the minimum number in the list and stores it in the global
 * list
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 */
void	ft_search_min_number(t_g_list *g_list)
{
	if (g_list->minimum > g_list->a_list->numbers)
	{
		g_list->minimum = g_list->a_list->numbers;
		g_list->nposition = g_list->ncount;
	}
}

/**
 * This function is used to find the maximum number in the list
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 */
void	ft_search_max_number(t_g_list *g_list)
{
	if (g_list->max <= g_list->b_list->numbers)
	{
		g_list->max = g_list->b_list->numbers;
		g_list->nposition2 = g_list->ncount;
	}
}