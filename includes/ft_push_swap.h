#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define BUFF_SIZE 50
# define MAX_FD 4864

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				i;
	int				sort;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				cmds_cnt;
	int				flag_v;
}				t_stacks;

int			get_next_line(int fd, char **line);
int			ft_stacks_free(t_stacks **stacks, int res);
int			ft_valid_int(int val_i, char *val_c);
int			ft_not_dupl(t_stack *stack, int val_i);
int			ft_get_count_nodes(t_stack *stack);
int			ft_node_iter_to_up(int len, int node_i);
int			ft_cmd_apply_s(t_stack **stack);
int			ft_cmd_apply_p(t_stack **src, t_stack **dst);
int			ft_cmd_apply_r(t_stack **stack);
int			ft_cmd_apply_rr(t_stack **stack);
int			ft_stack_set_tmp_cmds(t_stacks *stacks, t_stack *tmp_b);
int			ft_get_node_place_i(t_stack *stack, int node);
int			ft_node_b_to_a_count(int a, int b, int place_b);
int			ft_is_sorted(t_stacks *stacks);
int			ft_is_sort_stacks(t_stacks *stacks);
void		ft_stack_free(t_stack **stack);
void		ft_put_error(t_stacks **stacks, int tmp);
void		ft_stack_push_back(t_stack **stack, t_stack *new);
void		ft_stack_push_front(t_stack **stack, t_stack *new);
void		ft_stack_a_norm(t_stacks *stacks);
void		ft_set_index(t_stack *stack);
void		ft_cmd_apply_cnt(char *com, int cnt, t_stacks *stacks);
void		ft_print_stack(t_stacks *stacks);
void		ft_stack_a_to_b(t_stacks *stacks);
void		ft_stack_b_to_a(t_stacks *stacks);
void		ft_stack_copy_tmp_to_opt_cmds(t_stacks *stacks);
void		ft_node_b_to_a(t_stacks *stacks);
void		ft_stack_a_min_to_top(t_stacks *stacks);
void		ft_memdel(void **ap);
void		ft_strdel(char **as);
void		*ft_memalloc(size_t size);
char		*ft_strnew(size_t size);
t_stacks	*ft_create_stacks(int argc, char **argv);
t_stack		*ft_get_last_node(t_stack *stack);
t_stack		*ft_get_max_sort(t_stack *stack);
t_stack		*ft_stack_push_back_int(t_stack **stack, int val);
t_stack		*ft_create_new_node(int val);
t_stack		*ft_stack_pop_front(t_stack **stack);
t_stack		*ft_stack_pop_back(t_stack **stack);

#endif
