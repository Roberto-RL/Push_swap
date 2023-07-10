/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:55:24 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:36:49 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * If the number of elements in the list is 2 or 3,It determines the 
 * case of the list and then calls the function that will execute the case
 * 
 * @param g_list the global list
 */
void	ft_2or3(t_g_list *g_list)
{
	changenode (g_list, 0);
	g_list->numaux = g_list->a_list->numbers;
	changenode (g_list, 3);
	if (g_list->numaux < g_list->a_list->numbers
		|| g_list->a_list->previous->numbers == g_list->numaux)
	{
		if (g_list->a_list->numbers > g_list->a_list->previous->numbers
			&& g_list->numaux > g_list->a_list->previous->numbers)
			g_list->ncase = 1;
		else
			g_list->ncase = 4;
	}
	else
	{
		if (g_list->a_list->numbers > g_list->a_list->previous->numbers)
			g_list->ncase = 2;
		else if (g_list->numaux > g_list->a_list->previous->numbers)
			g_list->ncase = 3;
		else
			g_list->ncase = 5;
	}
	ft_ncases (g_list);
}

/**
 * It rotates the stack to the up or down depending on the number of cases
 * 
 * @param g_list the global list
 */
void	ft_ncases(t_g_list *g_list)
{
	if (g_list->ncase == 1)
		ft_sa(g_list);
	else if (g_list->ncase == 2 || g_list->ncase == 3)
	{
		ft_ra(g_list);
		write(1, "ra\n", 3);
	}
	else if (g_list->ncase == 4 || g_list->ncase == 5)
		ft_rra(g_list);
}

/**
 * If the number of elements in the list is 4 or 5, then push 
 * the smallest number to the top of the list, and then push 
 * it to the bottom of the list
 * 
 * @param g_list a pointer to the global list
 */
void	ft_4or5(t_g_list *g_list)
{
	g_list->largnum = 3;
	if (g_list->nposition == 1)
		ft_pb(g_list);
	else if (g_list->nposition <= g_list->ntotal / 2)
	{
		ft_ra(g_list);
		write(1, "ra\n", 3);
	}
	else if (g_list->nposition > g_list->ntotal / 2)
		ft_rra(g_list);
}

/**
 * It compares the position of the first node in the list with the position 
 * of the last node in the list
 * 
 * @param g_list a pointer to the global list
 */
void	ft_largenumbers(t_g_list *g_list)
{
	if (g_list->largnum == 0)
	{
		g_list->stacka = g_list->ntotal / BlockA;
		g_list->stackb = 0;
		g_list->largnum = 1;
	}
	ft_search_number_above(g_list);
	ft_search_number_below(g_list);
	g_list->ncompare1 = g_list->nposition - 1;
	g_list->ncompare2 = g_list->ntotal + 1 - g_list->nposition2;
	g_list->mode = 0;
	if (g_list->a_list != 0 && g_list->largnum != 2)
		ft_compare_position(g_list);
	else
		ft_change_listB(g_list);
}

/**
 * It changes the position of the node in the list
 * 
 * @param nposition The position of the node that will be moved to the top 
 * of the stack.
 * @param g_list is the global list that contains all the information about the
 * stack.
 */
void	changeposition(int nposition, t_g_list *g_list)
{
	int	aux;
	int	aux2;

	aux = nposition;
	changenode (g_list, 5);
	aux2 = g_list->nposition2;
	changenode (g_list, 2);
	g_list->nposition2 = aux2;
	if (g_list->ntotal % 2 != 0)
		g_list->ntotal += 1;
	if (g_list->ntotal2 % 2 != 0)
		g_list->ntotal2 += 1;
	if (nposition == 1)
	{
		ft_pb(g_list);
		g_list->bolrr = 0;
		if (g_list->stackb < g_list->b_list->index && g_list->ntotal2 != 0)
			g_list->bolrr = 1;
		g_list->stacka += 1;
		g_list->stackb += 1;
	}
	if (nposition != 1)
		ft_change_listA(g_list, aux);
}
