/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:09 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:02:11 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_op {
	sa = 0,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb
}	t_op;

typedef struct s_ops
{
	t_op	op;
	struct s_ops *pnext;
	struct s_ops *pprev;
}	t_ops;

typedef struct s_node {
	int		data;
	int		index;
	struct s_node *pnextnode;
	struct s_node *pprevnode;
}	t_node;

int		lengthList(t_node **stack);
t_node*	createNode(int data);
void	insertAddHead(t_node** head, int data);
t_node*	searchNode(t_node** head, int key);
void	SortList(t_node **head);
void	AddIndex(t_node **head, t_node **sorted);
void	push_a(t_node **src, t_node **dest, t_ops **ops);
void	push_b(t_node **src, t_node **dest, t_ops **ops);
void	swap_a(t_node** stack, t_ops **ops);
void	swap_b(t_node** stack, t_ops **ops);
void	rotateA(t_node** stack, t_ops **ops);
void	rotateB(t_node** stack, t_ops **ops);
void	reverse_rotateA(t_node** stack, t_ops **ops);
void	reverse_rotateB(t_node** stack, t_ops **ops);
void	remove_list(t_node **src);
void	record_op(t_ops **ops, t_op op);
int		ensure_capacity(t_ops **ops);
void	*my_realloc(void *ptr, size_t new_size, size_t old_size);
void	print_ops(t_ops **ops);
void	displayForward(t_node** head);
void	half_push_B(t_node **A, t_node **B, t_ops **ops);
void	half_push_A(t_node **B, t_node **A, t_ops **ops);
void	sort(t_node **B, t_ops **ops);
void	sort_n3(t_node **B, t_ops **ops);
void	operation(t_node **A, t_node **B, t_ops **ops);
int		check_sorted(t_node **A);
int		get_elm_num(t_node **A);
void	fix(t_node **A, t_node **B, t_ops **ops);
void	final_fix(t_node **A, t_ops **ops);

int		only_sb(t_node **B);
int		sb_rrb(t_node **B);
int		only_rb(t_node **B);
int		sb_rb(t_node **B);
int		only_rrb(t_node **B);

int	op_lengthList(t_ops **ops);

#endif
