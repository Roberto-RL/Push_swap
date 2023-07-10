/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:21 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/22 18:45:55 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * This function checks the input for errors
 * 
 * @param g_list a pointer to a struct that contains all the variables used 
 * in the program.
 * @param argv the array of strings that are the arguments passed to the program
 */
void	errorcheck1(t_g_list *g_list, char **argv)
{
	char		**mtemp;

	while (argv[g_list->i])
	{
		mtemp = ft_split(argv[g_list->i], ' ');
		if (mtemp == 0 || mtemp[0] == 0)
			g_list->berror = 1;
		g_list->z = 0;
		while (mtemp[g_list->z])
		{
			g_list->num = ft_atoi2(mtemp[g_list->z], g_list);
			inicialize_a_list(g_list);
			free(mtemp[g_list->z]);
			g_list->z++;
		}
		if (mtemp != 0)
			free(mtemp);
		g_list->i++;
	}
	changenode (g_list, 0);
	g_list->checkpass = 1;
	changenode (g_list, 3);
	if (g_list->berror == 0 && g_list->ncount > 1)
		check_equal(g_list);
	g_list->checkpass = 1;
}

/**
 * It creates a new node in the linked list and assigns the value of 
 * the number to the node
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 * 
 * @return the address of the first element of the list.
 */
void	inicialize_a_list(t_g_list *g_list)
{
	t_a_list	*temp;
	t_a_list	*aux;

	temp = malloc(sizeof(*temp));
	if (temp == 0)
		return ;
	temp->next = 0;
	temp->previous = 0;
	if (g_list->a_list == 0)
	{
		g_list->a_list = temp;
		g_list->a_list->next = 0;
		g_list->a_list->previous = 0;
	}
	else
	{
		aux = g_list->a_list;
		g_list->a_list->next = temp;
		g_list->a_list = g_list->a_list->next;
		g_list->a_list->previous = aux;
	}
	g_list->a_list->numbers = g_list->num;
}

/**
 * It checks to see if the number of nodes in the list is equal to the number of
 * nodes in the list
 * 
 * @param g_list is the global list that contains all the information of the
 * program.
 */
void	check_equal(t_g_list *g_list)
{
	g_list->checkpass = 0;
	g_list->i = 1;
	g_list->ndes = 1;
	changenode (g_list, 0);
	while (g_list->i < g_list->ntotal)
	{
		g_list->numaux = g_list->a_list->numbers;
		changenode (g_list, 3);
		changenode (g_list, 0);
		g_list->z = 1;
		while (g_list->z <= g_list->ndes)
		{
			g_list->a_list = g_list->a_list->next;
			g_list->z++;
		}
		g_list->ndes++;
		g_list->i++;
	}
	g_list->numaux = g_list->a_list->numbers;
}
