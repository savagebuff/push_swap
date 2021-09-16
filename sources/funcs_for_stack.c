#include "../includes/ft_push_swap.h"

static void	ft_if_argc_is_two(char **argv, t_stacks *stacks)
{
	int	i;
	int	val;

	argv = ft_split(argv[1], ' ');
	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			stacks->flag_v = 1;
		else
		{
			val = ft_atoi(argv[i]);
			if (ft_valid_int(val, argv[i]) == 0
				|| ft_not_dupl(stacks->a, val) == 0)
				ft_put_error(&stacks, ft_free_array(argv, 1));
			if ((ft_stack_push_back_int(&stacks->a, val)) == NULL)
				ft_put_error(&stacks, ft_free_array(argv, 1));
		}
		i++;
	}
	ft_free_array(argv, 1);
}

void	ft_create_stack_a(int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	val;

	if (argc == 2)
		ft_if_argc_is_two(argv, stacks);
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (ft_strcmp(argv[i], "-v") == 0)
				stacks->flag_v = 1;
			else
			{
				val = ft_atoi(argv[i]);
				if (ft_valid_int(val, argv[i]) == 0
					|| ft_not_dupl(stacks->a, val) == 0)
					ft_put_error(&stacks, ft_free_array(NULL, 1));
				if ((ft_stack_push_back_int(&stacks->a, val)) == NULL)
					ft_put_error(&stacks, ft_free_array(NULL, 1));
			}
		}
		ft_free_array(NULL, 1);
	}
}

t_stacks	*ft_create_stacks(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_put_error(&stacks, 1);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->flag_v = 0;
	stacks->cmds_cnt = 0;
	stacks->cmd_print = 0;
	ft_create_stack_a(argc, argv, stacks);
	return (stacks);
}
