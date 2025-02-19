/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:29 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:31 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*my_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	printf("old_size = %zu, new_size = %zu\n", old_size, new_size);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int	ensure_capacity(t_ops *ops)
{
	t_op	*new_list;
	int		new_cap;

	if (!ops)
		return (1);

	if (ops->size >= ops->capacity)
	{
		new_cap = (ops->capacity == 0) ? 42 : ops->capacity * 2;

		printf("Resizing op_size : old capacity = %d, new capacity = %d\n", ops->capacity, new_cap);

		new_list = my_realloc(ops->op_list, new_cap * sizeof(t_op), ops->capacity * sizeof(t_op));
		if (!new_list)
			exit(1);
		ops->op_list = new_list;
		ops->capacity = new_cap;
	}
	return (0);
}

void	record_op(t_ops *ops, t_op op)
{
	if (!ops)
		return ;
	if (ensure_capacity(ops))
		return ;
	if (ops->size >= ops->capacity)
	{
		fprintf(stderr, "Error: ops->size exceeded ops->capacity!\n");
		exit(1);
	}
	ops->op_list[ops->size] = op;
	ops->size++;

	printf("Recorded op at index: %d\n", ops->size);
}
