/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:18:24 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:22:38 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function is used to change the position of the stack A, 
 * in order to put the number in the right position
 * 
 * @param g_list the global list
 * @param aux the number of rotations needed to get to the desired position
 */
void	ft_change_listA(t_g_list *g_list, int aux)
{
	if (!(aux <= g_list->ntotal / 2) && g_list->bolrr == 1
		&& g_list->b_list != 0)
	{
		ft_rb(g_list);
		write(1, "rb\n", 3);
	}
	if (aux <= g_list->ntotal / 2 && g_list->bolrr == 1 && g_list->b_list != 0)
		ft_rr(g_list, aux);
	else if (g_list->a_list != 0
		&& g_list->a_list->index - 1 == g_list->a_list->next->index
		&& g_list->a_list->index > g_list->stacka
		&& g_list->a_list->next->index <= g_list->stacka)
		ft_sa(g_list);
	else if (aux <= g_list->ntotal / 2)
	{
		ft_ra(g_list);
		write(1, "ra\n", 3);
		aux--;
	}
	else if (aux > g_list->ntotal / 2)
	{
		ft_rra(g_list);
		aux++;
	}
	g_list->bolrr = 0;
}

/**
 * It searches for the largest number in the list and moves it to the top of the
 * list
 * 
 * @param g_list the global list
 */
void	ft_change_listB(t_g_list *g_list)
{
	int	aux;

	g_list->largnum = 2;
	changenode (g_list, 2);
	changenode (g_list, 5);
	aux = g_list->nposition2;
	changenode (g_list, 2);
	g_list->nposition2 = aux;
	if (g_list->ntotal2 % 2 != 0)
		g_list->ntotal2 += 1;
	if (g_list->nposition2 == 0 && g_list->largnum == 2)
		ft_pa(g_list);
	else if (g_list->nposition2 == 1 && g_list->b_list != 0
		&& g_list->b_list->index + 1 == g_list->b_list->next->index)
		ft_sb(g_list);
	else if (g_list->nposition2 <= g_list->ntotal2 / 2)
	{
		ft_rb(g_list);
		write(1, "rb\n", 3);
	}
	else if (g_list->nposition2 > g_list->ntotal2 / 2)
	{
		ft_rrb(g_list);
		write(1, "rrb\n", 4);
	}
}