#include "../includes/ft_push_swap.h"

int	ft_node_b_to_a_count(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0 && place_b != -1)
	{
		if (ft_revers(a) > ft_revers(b))
			return (ft_revers(a));
		else
			return (ft_revers(b));
	}
	else
		return (ft_revers(a) + ft_revers(b));
}

int	ft_get_node_place_i(t_stack *stack, int node)
{
	t_stack	*optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (stack)
	{
		if ((last_min == 0) || (last_min < 0 && stack->value - node < 0
				&& stack->value - node > last_min)
			|| (last_min > 0 && stack->value - node < last_min))
		{
			last_min = stack->value - node;
			optim = stack;
		}
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	if (optim == stack && last_min < 0)
		return (-1);
	if (last_min < 0)
		return (optim->i + 1);
	return (optim->i);
}

int	ft_node_iter_to_up(int len, int node_i)
{
	if (len / 2 >= node_i)
		return (node_i);
	else
		return ((len - node_i) * -1);
}

void	ft_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->i = i;
		i++;
		stack = stack->next;
	}	
}

t_stack	*ft_get_max_sort(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;
	t_stack	*first;
	int		nodes;
	int		i;

	first = stack;
	nodes = ft_get_count_nodes(stack);
	while (stack)
	{
		tmp = stack;
		i = -1;
		while (i++ < nodes)
		{
			if ((tmp->next == NULL ? first : tmp->next)->value < tmp->value)
				break ;
			stack->sort++;
			if (tmp->next == NULL)
				tmp = first;
		}
		max = stack;
		stack = stack->next;
	}
	return (max);
}
