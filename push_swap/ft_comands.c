/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:21:22 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/22 18:14:26 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It takes the first element of the B list and puts it at the beginning 
 * of the A list
 * 
 * @param g_list The global list that contains the two lists (a and b)
 */
void	ft_pa(t_g_list *g_list)
{
	t_a_list	*aux;

	changenode (g_list, 2);
	if (g_list->b_list != 0)
	{
		if (g_list->a_list == 0)
		{
			g_list->a_list = g_list->b_list;
			g_list->b_list = g_list->b_list->next;
			g_list->a_list->next = 0;
		}
		else
		{
			changenode (g_list, 2);
			aux = g_list->a_list;
			g_list->a_list->previous = g_list->b_list;
			g_list->a_list = g_list->a_list->previous;
			g_list->b_list = g_list->b_list->next;
			g_list->a_list->next = aux;
			g_list->a_list->previous = 0;
		}
		if (g_list->b_list != 0)
			g_list->b_list->previous = 0;
	}
	write(1, "pa\n", 3);
}

/**
 * It takes the first element of the list A and puts it at the beginning of the
 * list B
 * 
 * @param g_list the global list
 */
void	ft_pb(t_g_list *g_list)
{
	t_a_list	*aux;

	changenode (g_list, 2);
	if (g_list->a_list != 0)
	{
		if (g_list->b_list == 0)
		{
			g_list->b_list = g_list->a_list;
			g_list->a_list = g_list->a_list->next;
			g_list->b_list->next = 0;
		}
		else
		{
			changenode (g_list, 2);
			aux = g_list->b_list;
			g_list->b_list->previous = g_list->a_list;
			g_list->b_list = g_list->b_list->previous;
			g_list->a_list = g_list->a_list->next;
			g_list->b_list->next = aux;
			g_list->b_list->previous = 0;
		}
		if (g_list->a_list != 0)
			g_list->a_list->previous = 0;
	}
	write(1, "pb\n", 3);
}

/**
 * It takes the first node of the "list a", makes it the last node of the 
 * "list a", and then makes the second node of the list the first node of 
 * the list
 * 
 * @param g_list the global list
 */
void	ft_ra(t_g_list *g_list)
{
	t_a_list	*temp;
	t_a_list	*temp2;

	changenode (g_list, 0);
	temp = g_list->a_list;
	g_list->a_list = g_list->a_list->next;
	g_list->a_list->previous = 0;
	changenode (g_list, 3);
	temp2 = g_list->a_list;
	g_list->a_list = temp;
	g_list->a_list->next = 0;
	g_list->a_list->previous = temp2;
	g_list->a_list->previous->next = g_list->a_list;
}

/**
 * It takes the first node of the "list b" and makes it the last node of
 * the "list b"
 * 
 * @param g_list the global list
 */
void	ft_rb(t_g_list *g_list)
{
	t_a_list	*temp;
	t_a_list	*temp2;

	changenode (g_list, 1);
	temp = g_list->b_list;
	g_list->b_list = g_list->b_list->next;
	g_list->b_list->previous = 0;
	changenode (g_list, 4);
	temp2 = g_list->b_list;
	g_list->b_list = temp;
	g_list->b_list->next = 0;
	g_list->b_list->previous = temp2;
	g_list->b_list->previous->next = g_list->b_list;
	changenode (g_list, 1);
}

/**
 * It rotates both stacks to the top
 * 
 * @param g_list is the global list that contains all the information about the
 * stack.
 * @param aux is the number of operations that can be done.
 * 
 * @return The number of operations that have been performed.
 */
int	ft_rr(t_g_list *g_list, int aux)
{
	ft_ra(g_list);
	ft_rb(g_list);
	write(1, "rr\n", 3);
	aux--;
	return (aux);
}
