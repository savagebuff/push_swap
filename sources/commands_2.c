#include "../includes/ft_push_swap.h"

int	ft_cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_back(stack, ft_stack_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_p(t_stack **src, t_stack **dst)
{
	if (*src)
	{
		ft_stack_push_front(dst, ft_stack_pop_front(src));
		return (1);
	}
	return (-1);
}

int	ft_cmd_apply_s(t_stack **stack)
{
	int	res;

	if (*stack && (*stack)->next)
	{
		res = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = res;
		return (1);
	}
	return (-1);
}
