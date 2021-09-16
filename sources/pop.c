#include "../includes/ft_push_swap.h"

t_stack	*ft_stack_pop_back(t_stack **stack)
{
	t_stack	*last;
	t_stack	*res;

	last = *stack;
	res = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (last->next && last->next->next)
			last = last->next;
		res = last->next;
		last->next = NULL;
	}
	return (res);
}

t_stack	*ft_stack_pop_front(t_stack **stack)
{
	t_stack	*res;

	if (*stack == NULL)
		return (NULL);
	res = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = res->next;
	res->next = NULL;
	return (res);
}
