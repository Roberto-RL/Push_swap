/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:11:48 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/22 18:14:24 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It swaps the first two elements of the "list a"
 * 
 * @param g_list the global list that contains the stack a and stack b
 */
void	ft_sa(t_g_list *g_list)
{
	t_a_list	*aux;

	changenode (g_list, 0);
	aux = g_list->a_list;
	g_list->a_list = g_list->a_list->next;
	aux->next = g_list->a_list->next;
	if (g_list->a_list->next != 0)
		g_list->a_list->next->previous = aux;
	aux->previous = g_list->a_list;
	g_list->a_list->next = aux;
	g_list->a_list->previous = 0;
	write(1, "sa\n", 3);
}

/**
 * It swaps the first two elements of the stack B
 * 
 * @param g_list The global list that contains all the information about 
 * the stack.
 */
void	ft_sb(t_g_list *g_list)
{
	t_a_list	*aux;

	changenode (g_list, 1);
	aux = g_list->b_list;
	g_list->b_list = g_list->b_list->next;
	aux->next = g_list->b_list->next;
	if (g_list->b_list->next != 0)
		g_list->b_list->next->previous = aux;
	aux->previous = g_list->b_list;
	g_list->b_list->next = aux;
	g_list->b_list->previous = 0;
	write(1, "sb\n", 3);
}

/**
 * It takes the last node in the "list a" and makes it the first node in 
 * the "list a"
 * 
 * @param g_list the global list
 */
void	ft_rra(t_g_list *g_list)
{
	t_a_list	*temp;
	t_a_list	*temp2;

	if (g_list->a_list != 0)
	{
		changenode (g_list, 3);
		temp = g_list->a_list;
		g_list->a_list = g_list->a_list->previous;
		g_list->a_list->next = 0;
		changenode (g_list, 0);
		temp2 = g_list->a_list;
		g_list->a_list->previous = temp;
		g_list->a_list = g_list->a_list->previous;
		g_list->a_list->next = temp2;
		g_list->a_list->previous = 0;
	}
	write(1, "rra\n", 4);
}

/**
 * It takes the last node in the "list b" and makes it the first node in 
 * the "list b"
 * 
 * @param g_list the global list that contains all the information about 
 * the stack
 */
void	ft_rrb(t_g_list *g_list)
{
	t_a_list	*temp;
	t_a_list	*temp2;

	if (g_list->b_list != 0 && g_list->ntotal2 > 1)
	{
		changenode (g_list, 4);
		temp = g_list->b_list;
		g_list->b_list = g_list->b_list->previous;
		g_list->b_list->next = 0;
		changenode (g_list, 1);
		temp2 = g_list->b_list;
		g_list->b_list->previous = temp;
		g_list->b_list = g_list->b_list->previous;
		g_list->b_list->next = temp2;
		g_list->b_list->previous = 0;
	}
}

/**
 * It rotates both stacks to the down
 * 
 * @param g_list a pointer to the global list
 * @param aux is the number of operations that have been done.
 * 
 * @return The number of operations performed.
 */
int	ft_rrr(t_g_list *g_list, int aux)
{
	ft_rra(g_list);
	ft_rrb(g_list);
	write(1, "rrr\n", 4);
	aux++;
	return (aux);
}
