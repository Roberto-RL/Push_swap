/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:21:57 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:33:58 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It moving forward and checks
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 * 
 * @return the position of the number that is being
 * 		searched.
 */
void	ft_forward_node_A(t_g_list *g_list)
{
	t_a_list	*aux;

	aux = g_list->a_list;
	ft_initialize(g_list);
	while (g_list->a_list != 0 && g_list->a_list->next != 0)
	{
		if (g_list->mode == 1)
		{
			if (g_list->a_list->index >= 0
				&& g_list->stacka >= g_list->a_list->index)
			{	
				g_list->nposition = g_list->ncount;
				return ;
			}
		}
		ft_check_order(g_list);
		g_list->a_list = g_list->a_list->next;
		if (g_list->largnum == 0 || g_list->largnum == 3)
			ft_search_min_number(g_list);
		ft_compare(g_list, aux);
	}
	g_list->ntotal = g_list->ncount;
}

/**
 * This function checks to see if the list is in order, and if it is, it sets the
 * checkpass variable to 1
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 */
void	ft_check_order(t_g_list *g_list)
{
	if (g_list->checkpass != 0)
		g_list->ncount += 1;
	if (g_list->a_list->numbers > g_list->a_list->next->numbers)
	{
		g_list->check = 0;
		g_list->tidy = 0;
	}
}

/**
 * It compares the number of the auxiliar list with the number of the main list,
 * and if both numbers are the same, berror return a error, and the same time
 * add to the actual node a number equivalent to the final order number.
 * 
 * @param g_list This is the global list.
 * @param aux is a pointer to the current node of the list.
 */
void	ft_compare(t_g_list *g_list, t_a_list *aux)
{
	if (g_list->checkpass == 0)
	{
		if (g_list->numaux == g_list->a_list->numbers)
			g_list->berror = 1;
		ft_index(g_list, aux);
	}
}

/**
 * This function compares the position of the numbers in the list and changes the
 * position of the numbers in the list
 * 
 * @param g_list a pointer to the global list
 */
void	ft_compare_position(t_g_list *g_list)
{
	if (g_list->ncompare1 < g_list->ncompare2
		&& g_list->a_list->index <= g_list ->stacka)
		changeposition(g_list->nposition, g_list);
	else if (g_list->ncompare1 > g_list->ncompare2
		&& g_list->a_list->index <= g_list ->stacka)
		changeposition(g_list->nposition2, g_list);
	else if (g_list->ncompare1 == g_list->ncompare2
		&& g_list->a_list->index <= g_list ->stacka)
	{
		if (g_list->auxindex1 < g_list->auxindex2)
			changeposition(g_list->nposition, g_list);
		else
			changeposition(g_list->nposition2, g_list);
	}
}
