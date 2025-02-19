/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:05:11 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:05:12 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*pnextnode;
	struct s_node	*pprevnode;
}	t_node;
typedef enum e_op
{
	sa,
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
	t_op	*op_list;
	int		size;
	int		capacity;
}	t_ops;
void	*my_realloc(void *ptr, size_t new_size, size_t old_size);
void	ensure_capacity(t_ops *ops);
void	record_op(t_ops *ops, t_op op);
void	swap_a(t_node **stack, t_ops *ops);
void	swap_b(t_node **stack, t_ops *ops);
void	push_a(t_node **src, t_node **dest, t_ops *ops);
void	push_b(t_node **src, t_node **dest, t_ops *ops);
void	rotateA(t_node **stack, t_ops *ops);
void	rotateB(t_node **stack, t_ops *ops);
void	reverse_rotateA(t_node **stack, t_ops *ops);
void	reverse_rotateB(t_node **stack, t_ops *ops);
int		lengthList(t_node **stack);
void	push_chunk(t_node **A, t_node **B, int start, int end, t_ops *ops);
void	pushAtoB(t_node **A, t_node **B, t_ops *ops);
t_node	*createNode(int data);
void	insertAddHead(t_node **head, int data);
t_node	*searchNode(t_node **head, int key);
void	AddIndex(t_node **head, t_node **sorted);
void	SortList(t_node **head);
int		insertPosition(t_node **A, int index);
void	rotateA_with_pos(t_node **A, int pos, t_ops *ops);
void	subsort(t_node **A, t_ops *ops);
void	pushBtoA(t_node **A, t_node **B, t_ops *ops);
int		searchMinNode(t_node **A);
void	fix(t_node **A, t_ops *ops);
void	print_ops(t_ops *ops);

#endif
