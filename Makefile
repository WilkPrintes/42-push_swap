NAME		:= push_swap

CC			:= gcc

LIBFT		:= ./includes/libft/libft.a

LIBFT_PATH	:= ./includes/libft

LIBFT_FLAGS	:= -L $(LIBFT_PATH) -lft

HEADER_DIR	:= ./includes ./includes/libft

INCLUDE		:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_DIR		:= ./src/

SRC_FILE	:=  push_swap.c moviments.c push_swap_utils.c

SRC			:=	$(foreach file, $(SRC_FILE), $(SRC_DIR)$(file))

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	@$(CC) -g $(SRC) -o $@ $(INCLUDE) $(LIBFT_FLAGS)
	@echo "\033[0;32mcompiled  (>‿◠)\033[0m"

$(LIBFT):
	@make -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[0;31mpush_swap deleted (ㆆ_ㆆ)\033[0m"

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf *.o

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

norma:
	@norminette ./

.PHONY: all fclean re