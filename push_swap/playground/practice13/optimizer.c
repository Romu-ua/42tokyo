/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamamototaimu <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:09:45 by yamamototaimu     #+#    #+#             */
/*   Updated: 2025/02/19 17:09:47 by yamamototaimu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	remove_op(t_ops **ops)
{
	t_ops	*tmp;

	tmp = *ops;
	if (!ops || !*ops)
		return ;
	if (tmp->pnext == tmp)
	{
		free(tmp);
		*ops = NULL;
		return ;
	}
	tmp->pprev->pnext = tmp->pnext;
	tmp->pnext->pprev = tmp->pprev;
	*ops = tmp->pnext;
	free(tmp);
}

void optimizer(t_ops **ops)
{
    t_ops *curr = *ops;
    while (curr && curr->pnext)
    {
        t_ops *next = curr->pnext;

        // 逆操作の削除
        if ((curr->op == pa && next->op == pb) ||
            (curr->op == pb && next->op == pa) ||
            (curr->op == ra && next->op == rra) ||
            (curr->op == rra && next->op == ra) ||
            (curr->op == rb && next->op == rrb) ||
            (curr->op == rrb && next->op == rb) ||
            (curr->op == sa && next->op == sa) ||
            (curr->op == sb && next->op == sb))
        {
            remove_op(&curr);
            remove_op(&next);
            curr = *ops;  // 最適化が発生したので、リストの先頭からやり直す
            continue;
        }

        // 連結可能な操作の圧縮
        if ((curr->op == ra && next->op == rb) ||
            (curr->op == rb && next->op == ra))
        {
            curr->op = rr;
            remove_op(&next);
            curr = *ops;  // 再スキャン
            continue;
        }
        if ((curr->op == rra && next->op == rrb) ||
            (curr->op == rrb && next->op == rra))
        {
            curr->op = rrr;
            remove_op(&next);
            curr = *ops;
            continue;
        }
        if ((curr->op == sa && next->op == sb) ||
            (curr->op == sb && next->op == sa))
        {
            curr->op = ss;
            remove_op(&next);
            curr = *ops;
            continue;
        }
        curr = curr->pnext;
    }
}
