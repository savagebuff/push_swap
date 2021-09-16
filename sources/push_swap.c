#include "../includes/ft_push_swap.h"

static void	ft_sort_other(t_stacks *stacks)
{
	ft_stack_a_to_b(stacks);
	ft_stack_b_to_a(stacks);
	ft_stack_a_min_to_top(stacks);
}

static void	ft_sort_three(t_stacks *stacks)
{
	if (stacks->a->value > stacks->a->next->value
		&& stacks->a->value < stacks->a->next->next->value)
		ft_cmd_apply_cnt("sa", 1, stacks);
	else if (stacks->a->value > stacks->a->next->next->value)
		ft_cmd_apply_cnt("ra", 1, stacks);
	else if (stacks->a->value < stacks->a->next->value
		&& stacks->a->next->value > stacks->a->next->next->value)
	{
		ft_cmd_apply_cnt("rra", 1, stacks);
		ft_cmd_apply_cnt("sa", 1, stacks);
	}
}

static void	ft_sort_five(t_stacks *stacks)
{
	if (stacks->max_sort->sort < 3)
	{
		ft_cmd_apply_cnt("pb", 2, stacks);
		ft_sort_three(stacks);
	}
	else
		ft_stack_a_to_b(stacks);
	ft_stack_b_to_a(stacks);
	ft_stack_a_min_to_top(stacks);
}

void	ft_stack_a_norm(t_stacks *stacks)
{
	int	com;

	ft_set_index(stacks->a);
	stacks->max_sort = ft_get_max_sort(stacks->a);
	stacks->len_a = ft_get_count_nodes(stacks->a);
	if (stacks->len_a - stacks->max_sort->i - stacks->max_sort->sort > 0)
		com = stacks->len_a - (stacks->len_a
				- stacks->max_sort->i - stacks->max_sort->sort);
	else
		com = ft_revers(stacks->len_a
				- stacks->max_sort->i - stacks->max_sort->sort);
	com = ft_node_iter_to_up(stacks->len_a, com);
	if (com > 0 && stacks->len_a != 1)
		ft_cmd_apply_cnt("ra", com, stacks);
	else if (com <= 0 && stacks->len_a != 1)
		ft_cmd_apply_cnt("rra", com, stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_create_stacks(argc, argv);
	if (stacks->a == NULL)
		exit(ft_stacks_free(&stacks, 0));
	stacks->cmd_print = 1;
	stacks->len_a = ft_get_count_nodes(stacks->a);
	ft_stack_a_norm(stacks);
	if (ft_is_sorted(stacks) == 0)
		exit(ft_stacks_free(&stacks, 0));
	if (stacks->len_a == 3)
		ft_sort_three(stacks);
	else if (stacks->len_a == 5)
		ft_sort_five(stacks);
	else
		ft_sort_other(stacks);
	return (ft_stacks_free(&stacks, 0));
}
