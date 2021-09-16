#include "../includes/ft_push_swap.h"

void	ft_stack_a_min_to_top(t_stacks *stacks)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		iter;

	tmp_a = stacks->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->value < min_node->value)
			min_node = tmp_a;
		tmp_a = tmp_a->next;
	}
	stacks->len_a = ft_get_count_nodes(stacks->a);
	ft_set_index(stacks->a);
	iter = ft_node_iter_to_up(stacks->len_a, min_node->i);
	if (iter > 0)
		ft_cmd_apply_cnt("ra", iter, stacks);
	else
		ft_cmd_apply_cnt("rra", iter, stacks);
}

void	ft_stack_a_to_b(t_stacks *stacks)
{
	t_stack	*stack_a;

	stack_a = stacks->a;
	while (stack_a && stack_a->i != stacks->max_sort->i)
	{
		stack_a = stack_a->next;
		ft_cmd_apply_cnt("pb", 1, stacks);
	}
}

void	ft_node_b_to_a(t_stacks *stacks)
{
	stacks->tmp_a = ft_revers(stacks->opt_a);
	stacks->tmp_b = ft_revers(stacks->opt_b);
	while (((stacks->opt_b > 0 && stacks->opt_a > 0) || (stacks->opt_b < 0
				&& stacks->opt_a < 0)) && stacks->tmp_a
		&& stacks->tmp_b && stacks->opt_pl != -1)
	{
		if (stacks->opt_b > 0)
			ft_cmd_apply_cnt("rr", 1, stacks);
		else
			ft_cmd_apply_cnt("rrr", 1, stacks);
		stacks->tmp_b--;
		stacks->tmp_a--;
	}
	if (stacks->opt_b > 0)
		ft_cmd_apply_cnt("rb", stacks->tmp_b, stacks);
	else
		ft_cmd_apply_cnt("rrb", stacks->tmp_b, stacks);
	if (stacks->opt_pl != -1 && stacks->opt_a > 0)
		ft_cmd_apply_cnt("ra", stacks->tmp_a, stacks);
	if (stacks->opt_pl != -1 && stacks->opt_a <= 0)
		ft_cmd_apply_cnt("rra", stacks->tmp_a, stacks);
	ft_cmd_apply_cnt("pa", 1, stacks);
	if (stacks->opt_pl == -1)
		ft_cmd_apply_cnt("ra", 1, stacks);
}

void	ft_stack_b_to_a(t_stacks *stacks)
{
	t_stack	*tmp_b;
	int		min_cmds;
	int		cmds;

	while (stacks->b)
	{
		tmp_b = stacks->b;
		ft_set_index(stacks->a);
		ft_set_index(stacks->b);
		stacks->len_a = ft_get_count_nodes(stacks->a);
		stacks->len_b = ft_get_count_nodes(stacks->b);
		min_cmds = ft_stack_set_tmp_cmds(stacks, tmp_b);
		ft_stack_copy_tmp_to_opt_cmds(stacks);
		while (tmp_b)
		{
			cmds = ft_stack_set_tmp_cmds(stacks, tmp_b);
			if (min_cmds > cmds)
			{
				min_cmds = cmds;
				ft_stack_copy_tmp_to_opt_cmds(stacks);
			}
			tmp_b = tmp_b->next;
		}
		ft_node_b_to_a(stacks);
	}
}
