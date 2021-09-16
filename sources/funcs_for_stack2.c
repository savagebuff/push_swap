#include "../includes/ft_push_swap.h"

int	ft_get_count_nodes(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_create_new_node(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->value = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_get_last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
