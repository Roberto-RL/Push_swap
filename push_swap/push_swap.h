/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:07:44 by rrimonte          #+#    #+#             */
/*   Updated: 2023/03/28 18:34:05 by rrimonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
#define BlockA 16.5

typedef struct s_g_list
{
	struct s_a_list	*a_list;
	struct s_a_list	*b_list;
	int				i;
	int				x;
	int				z;
	int				num;
	int				numaux;
	int				nposition;
	int				nposition2;
	int				ncompare1;
	int				ncompare2;
	int				minimum;
	int				max;
	int				tidy;
	int				berror;
	int				ncount;
	int				ntotal;
	int				ntotal2;
	int				ncase;
	int				count;
	int				check;
	int				ndes;
	int				checkpass;
	int				mode;
	int				largnum;
	int				changenode;
	int				stacka;
	int				stackb;
	int				auxindex1;
	int				auxindex2;
	int				bolrr;
}	t_g_list;
typedef struct s_a_list
{
	struct s_a_list	*previous;
	struct s_a_list	*next;
	int				numbers;
	int				index;
}	t_a_list;

void	ft_push_swap(t_g_list *g_list, char **argv);
void	ft_cases(t_g_list *g_list);
void	ft_2or3(t_g_list *g_list);
void	ft_4or5(t_g_list *g_list);
void	ft_largenumbers(t_g_list *g_list);
int		ft_atoi2(const char *str, t_g_list *g_list);
void	changenode(t_g_list *g_list, int dirbol);
void	ft_backward_node(t_g_list *g_list, int dirbol);
void	ft_forward_node(t_g_list *g_list, int dirbol);
void	ft_initialize_node(t_g_list *g_list);
void	ft_forward_node_A(t_g_list *g_list);
void	ft_check_order(t_g_list *g_list);
void	ft_search_min_number(t_g_list *g_list);
void	ft_search_max_number(t_g_list *g_list);
void	ft_compare(t_g_list *g_list, t_a_list *aux);
void	errorcheck1(t_g_list *g_list, char **argv);
void	inicialize_a_list(t_g_list *g_list);
void	check_equal(t_g_list *g_list);
void	ft_deletenod(t_g_list *buff);
void	ft_rra(t_g_list *g_list);
void	ft_rrb(t_g_list *g_list);
int		ft_rrr(t_g_list *g_list, int aux);
void	ft_ra(t_g_list *g_list);
void	ft_rb(t_g_list *g_list);
int		ft_rr(t_g_list *g_list, int aux);
void	ft_pa(t_g_list *g_list);
void	ft_pb(t_g_list *g_list);
void	ft_sa(t_g_list *g_list);
void	ft_sb(t_g_list *g_list);
void	ft_compare_position(t_g_list *g_list);
void	ft_change_listA(t_g_list *g_list, int aux);
void	ft_change_listB(t_g_list *g_list);
void	changeposition(int nposition, t_g_list *g_list);
void	ft_index(t_g_list *g_list, t_a_list *aux);
void	ft_search_number_above(t_g_list *g_list);
void	ft_search_number_below(t_g_list *g_list);

#endif