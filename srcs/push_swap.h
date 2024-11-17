/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:21:29 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:56:33 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	bool			div;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}		t_list;

int					main(int ac, char **av);

//error
int					syntax_errors(char *str);
int					dup_error(t_list *a, int nb);
void				free_lst(t_list **lst);
void				free_errors(t_list **a);
void				exit_error_av(t_list **a, t_list **b);

//OPPERATOR
void				push(t_list **dest, t_list **src);
void				swap(t_list **head);
void				rotate(t_list **lst);
void				reverse_rotate(t_list **lst);

//PRINT
void				pa(t_list **a, t_list **b, bool print);
void				pb(t_list **a, t_list **b, bool print);
void				rra(t_list **a, bool print);
void				rrb(t_list **b, bool print);
void				rrr(t_list **a, t_list **b, bool print);
void				ra(t_list **a, bool print);
void				rb(t_list **b, bool print);
void				rr(t_list **a, t_list **b, bool print);
void				sa(t_list **a, bool print);
void				sb(t_list **b, bool print);
void				ss(t_list **a, t_list **b, bool print);

//NODE
void				make_lst_a(t_list *a, t_list *b);
void				make_lst_b(t_list *a, t_list *b);
void				prep_to_push(t_list **lst, t_list *top_node,
						char lst_name);
void				find_target(t_list *a, t_list *b);

//SORT
void				sort_three(t_list **a);
void				sort_lst(t_list **a, t_list **b);
void				rotate_both(t_list **a, t_list **b, t_list *cheap);
void				move_a_to_b(t_list **a, t_list **b);
void				move_b_to_a(t_list **a, t_list **b);

void				rev_rot_both(t_list **a, t_list **b,
						t_list *cheap);

t_list				*get_cheapest_nb(t_list *lst);

/*//utils//*/

t_list				*lst_last(t_list *lst);
int					lst_size(t_list *lst);
bool				lst_sorted(t_list *lst);
void				define_index(t_list *lst);
t_list				*find_min(t_list *lst);
t_list				*find_max(t_list *lst);
void				find_target_a(t_list *a, t_list *b);
void				find_target_b(t_list *a, t_list *b);
void				cost_move(t_list *a, t_list *b);
void				cheapest_moves(t_list *lst);

#endif
