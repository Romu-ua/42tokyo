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

void	ensure_capacity(t_ops *ops)
{
	t_op	*new_list;
	int		new_cap;

	if (ops->size >= ops->capacity)
	{
		new_cap = (ops->capacity == 0) ? 42 : ops->capacity * 2;
		new_list = my_realloc(ops->op_list, new_cap * sizeof(t_op), ops->size * sizeof(t_op));
		if (!new_list)
			exit(1);
		ops->op_list = new_list;
		ops->capacity = new_cap;
	}
}

void	record_op(t_ops *ops, t_op op)
{
	ensure_capacity(ops);
	ops->op_list[ops->size] = op;
	ops->size++;
}
