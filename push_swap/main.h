#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef enum e_op
{
	sa = 0,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
	rr,
	rrr,
	ss,
}	t_op;
typedef struct s_ops
{
	t_op			op;
	struct s_ops	*pnext;
	struct s_ops	*pprev;
}	t_ops;
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*pnext;
	struct s_node	*pprev;
}	t_node;

long	ft_atol(const char *nptr);
int		input_check(int argc, char **argv);
void	insert_add_head(t_node **head, int data);
void	ft_sort(int *arr, int size);
int		list_len(t_node **a);
void	addidx(t_node **a, char **argv);
void	simple_sort(t_node **a, t_ops **ops, int size);
void	print_ops(t_ops **ops);
void	sort_three_a(t_node **a, t_ops **ops);
void	sort_three_b(t_node **b, t_ops **ops);
int		check_sorted_a(t_node **a);
void	push_a(t_node **src, t_node **dest, t_ops **ops);
void	push_b(t_node **src, t_node **dest, t_ops **ops);
void	swap_a(t_node **stack, t_ops **ops);
void	swap_b(t_node **stack, t_ops **ops);
void	rotate_a(t_node **stack, t_ops **ops);
void	rotate_b(t_node **stack, t_ops **ops);
void	reverse_rotate_a(t_node **stack, t_ops **ops);
void	reverse_rotate_b(t_node **stack, t_ops **ops);
void	record_op(t_ops **ops, t_op op);
void	print_ops(t_ops **ops);

void	sort_fix(t_node **a, t_node **b, t_ops **ops);
void	threshold_push_b(t_node **a, t_node **b, t_ops **ops, int threshold);
void	threshold_push_a(t_node **a, t_node **b, t_ops **ops, int threshold);
void	operation(t_node **a, t_ops **ops);
// void	optimizer(t_ops **ops);
int		start_node(t_node **a);


#endif
