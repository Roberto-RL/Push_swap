/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:15:14 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:33:59 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It changes the node position of the g_list
 * 
 * @param g_list the global list
 * @param dirbol 0 = backward "list a", 1 = backward "list b", 2 = backward both
 * , 3 = forward "list a", 4 = forward "list b", 5 = forward both
 */
void	changenode(t_g_list *g_list, int dirbol)
{
	g_list->nposition2 = 1;
	if (dirbol == 0 || dirbol == 1 || dirbol == 2)
		ft_backward_node(g_list, dirbol);
	if (dirbol == 3 || dirbol == 4 || dirbol == 5)
		ft_forward_node(g_list, dirbol);
}

/**
 * This function moves the current node to the begining of the list
 * 
 * @param g_list The global list that contains all the information about the
 * program.
 * @param dirbol 0 = a_list, 1 = b_list, 2 = both
 * 
 * @return the number of nodes in the list.
 */
void	ft_backward_node(t_g_list *g_list, int dirbol)
{
	if (dirbol == 0 || dirbol == 2)
	{
		g_list->nposition2 = g_list->ntotal;
		while (g_list->a_list != 0 && g_list->a_list->previous != 0)
		{
			if (g_list->mode == 1)
			{
				if (g_list->a_list->index >= 0
					&& g_list->stacka >= g_list->a_list->index)
					return ;
			}
			g_list->nposition2 -= 1;
			g_list->a_list = g_list->a_list->previous;
		}
	}
	if (dirbol == 1 || dirbol == 2)
	{
		while (g_list->b_list != 0 && g_list->b_list->previous != 0)
		{	
			g_list->b_list = g_list->b_list->previous;
		}
	}
}

/**
 * It moves the pointer to the last node of the list
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 * @param dirbol This is the direction of the list.
 */
void	ft_forward_node(t_g_list *g_list, int dirbol)
{
	if (dirbol == 3 || dirbol == 5)
		ft_forward_node_A(g_list);
	if (dirbol == 4 || dirbol == 5)
	{
		if (g_list->largnum == 2)
			g_list->max = g_list->b_list->numbers;
		if (g_list->checkpass != 0)
			g_list->ncount = 0;
		while (g_list->b_list != 0 && g_list->b_list->next != 0)
		{
			if (g_list->largnum == 2 || g_list->largnum == 1)
				ft_search_max_number(g_list);
			g_list->ncount += 1;
			g_list->b_list = g_list->b_list->next;
		}
		if (g_list->largnum == 2)
			ft_search_max_number(g_list);
		g_list->ntotal2 = g_list->ncount;
	}
}

/**
 * This function initializes the global variables that are used in the program
 * 
 * @param g_list This is the global list that contains all the parameters.
 */
void	ft_initialize_node(t_g_list *g_list)
{
	g_list->tidy = 1;
	g_list->check = 1;
	if (g_list->largnum == 0 || g_list->largnum == 3)
		g_list->nposition = 1;
	if (g_list->checkpass != 0)
		g_list->ncount = 1;
	if (g_list->b_list != 0)
		g_list->tidy = 0;
	if (g_list->a_list != 0)
		g_list->minimum = g_list->a_list->numbers;
}

/**
 * It deletes the first node in the list
 * 
 * @param g_list the global list
 */
void	ft_deletenod(t_g_list *g_list)
{
	t_a_list	*temp;

	temp = 0;
	if (g_list->a_list->next != 0)
		temp = g_list->a_list->next;
	if (g_list->a_list->next != 0)
		g_list->a_list->next->previous = g_list->a_list->previous;
	free (g_list->a_list);
	g_list->a_list = temp;
}
