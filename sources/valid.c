#include "../includes/ft_push_swap.h"

int	ft_valid_int(int val_i, char *val_c)
{
	char	*tmp;
	int		res;

	res = 0;
	tmp = ft_itoa(val_i);
	if (ft_strcmp(tmp, val_c) == 0)
		res = 1;
	if (tmp)
		free(tmp);
	return (res);
}

int	ft_not_dupl(t_stack *stack, int val_i)
{
	while (stack)
	{
		if (stack->value == val_i)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_sorted(t_stacks *stacks)
{
	t_stack	*stack_a;
	int		len;

	len = stacks->len_a;
	stack_a = stacks->a;
	while (stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (1);
	}
	return (0);
}

int	ft_is_sort_stacks(t_stacks *stacks)
{
	t_stack	*stack_a;
	int		last_val;

	stack_a = stacks->a;
	last_val = stack_a->value;
	while (stack_a)
	{
		if (last_val > stack_a->value)
			return (0);
		last_val = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
