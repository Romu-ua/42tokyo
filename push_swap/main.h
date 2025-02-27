#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

#endif
