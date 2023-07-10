/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:27 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/22 19:07:02 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_index(t_g_list *g_list, t_a_list *aux)
{
    if (g_list->numaux > g_list->a_list->numbers)
		aux->index += 1;
	else if (g_list->numaux < g_list->a_list->numbers)
		g_list->a_list->index += 1;
}