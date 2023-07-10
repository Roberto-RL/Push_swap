/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:28:39 by rrimonte          #+#    #+#             */
/*   Updated: 2023/04/25 08:42:16 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It takes the arguments from the command line, and puts them into a linked list
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the array of strings passed to the program
 * 
 * @return the value of the function ft_main2.
 */
int	main(int argc, char **argv)
{
	t_g_list	*g_list;

	if (argc == 1)
		return (0);
	g_list = malloc(sizeof(*g_list));
	if (g_list == 0)
		return (0);
	g_list->i = 1;
	g_list->x = 0;
	g_list->berror = 0;
	g_list->tidy = 0;
	g_list->a_list = 0;
	g_list->b_list = 0;
	g_list->changenode = 0;
	if (argc > 1)
		ft_push_swap (g_list, argv);
	if (g_list->berror == 1)
		return (0);
	changenode (g_list, 0);
	while (g_list->a_list != 0)
			ft_deletenod(g_list);
	free(g_list);
	return (0);
}

/**
 * It checks for errors, then sorts the list
 * 
 * @param g_list This is the global list that contains all the information about
 * the stack.
 * @param argv the array of strings that are the arguments passed to the program
 * 
 * @return the number of arguments that are being passed to the program.
 */
void	ft_push_swap(t_g_list *g_list, char **argv)
{
	g_list->check = 0;
	errorcheck1(g_list, argv);
	if (g_list->berror == 1)
	{
		changenode (g_list, 0);
		while (g_list->a_list != 0)
			ft_deletenod(g_list);
		free(g_list);
		write(2, "Error\n", 6);
		return ;
	}
	g_list->tidy = 0;
	while (g_list->tidy == 0 && g_list->berror == 0)
		ft_cases(g_list);
}

/**
 * It checks if the stack is sorted, if not, it checks if the stack is 2 or 3
 * numbers, if not, if the stack is 4 or 5 numbers,if not checks if
 * the stack is 6 or more numbers, and checks if the numbers are in the correct
 * order
 * 
 * @param g_list the global list
 */
void	ft_cases(t_g_list *g_list)
{
	changenode (g_list, 0);
	changenode (g_list, 3);
	if (g_list->ntotal <= 3 && g_list->tidy == 0 && g_list->check == 0
		&& (g_list->largnum == 0 || g_list->largnum == 3))
		ft_2or3 (g_list);
	else if ((g_list->ntotal > 3 && 6 > g_list->ntotal) && g_list->tidy == 0
		&& g_list->check == 0 && (g_list->largnum == 0 || g_list->largnum == 3))
		ft_4or5(g_list);
	else if (g_list->tidy == 0 && g_list->largnum != 3)
		ft_largenumbers(g_list);
	else if (g_list->check == 1 && g_list->tidy == 0 && g_list->mode == 0)
		ft_pa(g_list);
	g_list->mode = 0;
	changenode (g_list, 0);
	changenode (g_list, 3);
}
