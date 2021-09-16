#include "../includes/ft_push_swap.h"

static void	if_else_stack_a(t_stack *stack_a)
{
	if (stack_a)
	{
		ft_putnbr_fd(stack_a->value, 1);
		stack_a = stack_a->next;
	}
	else
	{
		ft_putchar_fd('-', 1);
		stack_a = NULL;
	}
}

void	ft_print_stack(t_stacks *stacks)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stacks->a;
	stack_b = stacks->b;
	while (stack_a || stack_b)
	{
		if_else_stack_a(stack_a);
		ft_putstr_fd(" | ", 1);
		if (stack_b)
			ft_putnbr_fd(stack_b->value, 1);
		else
			ft_putchar_fd('-', 1);
		ft_putchar_fd('\n', 1);
		if (stack_a)
			stack_a = stack_a->next;
		else
			stack_a = NULL;
		if (stack_b)
			stack_b = stack_b->next;
		else
			stack_b = NULL;
	}
	ft_putchar_fd('\n', 1);
}

static void	ft_cmd_print(char *com)
{
	ft_putstr_fd(com, 1);
	ft_putchar_fd('\n', 1);
}

static int	ft_cmd_apply(char *c, t_stacks *stacks)
{
	int	len;
	int	res;

	len = ft_strlen(c);
	res = 0;
	if (len == 2 && c[0] == 's' && (c[1] == 's' || c[1] == 'a'))
		res = ft_cmd_apply_s(&stacks->a);
	if (len == 2 && c[0] == 's' && (c[1] == 's' || c[1] == 'b'))
		res = ft_cmd_apply_s(&stacks->b);
	if (len == 2 && c[0] == 'p' && c[1] == 'a')
		res = ft_cmd_apply_p(&stacks->b, &stacks->a);
	if (len == 2 && c[0] == 'p' && c[1] == 'b')
		res = ft_cmd_apply_p(&stacks->a, &stacks->b);
	if (len == 2 && c[0] == 'r' && (c[1] == 'r' || c[1] == 'a'))
		res = ft_cmd_apply_r(&stacks->a);
	if (len == 2 && c[0] == 'r' && (c[1] == 'r' || c[1] == 'b'))
		res = ft_cmd_apply_r(&stacks->b);
	if (len == 3 && c[0] == 'r' && c[1] == 'r' && (c[2] == 'r' || c[2] == 'a'))
		res = ft_cmd_apply_rr(&stacks->a);
	if (len == 3 && c[0] == 'r' && c[1] == 'r' && (c[2] == 'r' || c[2] == 'b'))
		res = ft_cmd_apply_rr(&stacks->b);
	if (res == 0)
		return (0);
	return (1);
}

void	ft_cmd_apply_cnt(char *com, int cnt, t_stacks *stacks)
{
	int	i;

	i = ft_revers(cnt);
	while (i)
	{
		if (ft_cmd_apply(com, stacks))
		{
			if (stacks->cmd_print == 1)
				ft_cmd_print(com);
			if (stacks->cmd_print == 1 && stacks->flag_v == 1)
				ft_print_stack(stacks);
			stacks->cmds_cnt++;
		}
		else
			ft_put_error(&stacks, 0);
		i--;
	}	
}
