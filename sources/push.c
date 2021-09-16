#include "../includes/ft_push_swap.h"

void	ft_stack_push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_get_last_node(*stack);
	last->next = new;
}

t_stack	*ft_stack_push_back_int(t_stack **stack, int val)
{
	t_stack	*new;

	new = ft_create_new_node(val);
	if (new == NULL)
		return (NULL);
	ft_stack_push_back(stack, new);
	return (*stack);
}
