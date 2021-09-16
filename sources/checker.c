#include "../includes/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*cmd;

	cmd = NULL;
	stacks = ft_create_stacks(argc, argv);
	stacks->cmd_print = 0;
	if (stacks->a == NULL)
		exit(ft_stacks_free(&stacks, 0));
	while (get_next_line(0, &cmd))
	{
		ft_cmd_apply_cnt(cmd, 1, stacks);
		if (cmd)
			free(cmd);
	}
	if (ft_is_sort_stacks(stacks))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_stacks_free(&stacks, 0));
}
