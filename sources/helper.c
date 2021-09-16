#include "../includes/ft_push_swap.h"

void	ft_stack_copy_tmp_to_opt_cmds(t_stacks *stacks)
{
	stacks->opt_a = stacks->tmp_a;
	stacks->opt_b = stacks->tmp_b;
	stacks->opt_pl = stacks->tmp_pl;
}

int	ft_stack_set_tmp_cmds(t_stacks *stacks, t_stack *tmp_b)
{
	stacks->tmp_pl = ft_get_node_place_i(stacks->a, tmp_b->value);
	stacks->tmp_b = ft_node_iter_to_up(stacks->len_b, tmp_b->i);
	stacks->tmp_a = ft_node_iter_to_up(stacks->len_a, stacks->tmp_pl);
	return (ft_node_b_to_a_count(stacks->tmp_a, stacks->tmp_b, stacks->tmp_pl));
}

void	ft_stack_free(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int	ft_stacks_free(t_stacks **stacks, int res)
{
	if (*stacks && (*stacks)->a)
		ft_stack_free(&(*stacks)->a);
	if (*stacks && (*stacks)->b)
		ft_stack_free(&(*stacks)->b);
	if (*stacks)
		free(*stacks);
	return (res);
}

void	ft_put_error(t_stacks **stacks, int res)
{
	ft_putstr_fd("Error\n", 1);
	ft_stacks_free(stacks, res);
	exit(res);
}
