NAME_LIB		=	libft.a

HEADER_NAME		=	ft_push_swap.h
NAME_PS			=	push_swap
NAME_CHECK		=	checker

INC_DIR			=	./includes/
INC_LIB			=	./libft/
SRC_DIR			=	./sources/
OBJ_DIR			=	./obj/

SRC_NAME_PS		=	commands_2.c commands.c funcs_for_stack.c helper.c pop.c \
									push_swap.c push.c sort_helper.c sort.c valid.c funcs_for_stack2.c

SRC_NAME_CHECK	=	commands_2.c commands.c funcs_for_stack.c helper.c pop.c \
									checker.c push.c sort_helper.c sort.c valid.c funcs_for_stack2.c get_next_line.c get_next_line_utils.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_PS			=	$(addprefix $(SRC_DIR), $(SRC_NAME_PS))
SRC_CHECK		=	$(addprefix $(SRC_DIR), $(SRC_NAME_CHECK))
OBJ_PS			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_PS:.c=.o))
OBJ_CHECK		=	$(addprefix $(OBJ_DIR), $(SRC_NAME_CHECK:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
GCC_LIBFT		=	-L ./libft/ -l ft

all: $(NAME_PS)

$(NAME_PS): $(OBJ_DIR) $(OBJ_PS) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_PS) $(FLAGS) -o $(NAME_PS)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB) $(FLAGS) $< -o $@

bonus: $(NAME_CHECK)

$(NAME_CHECK): $(OBJ_DIR) $(OBJ_CHECK) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_CHECK) $(FLAGS) -o $(NAME_CHECK)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_PS)
	@/bin/rm -f $(NAME_CHECK)
	@make fclean -C libft/

re: fclean all