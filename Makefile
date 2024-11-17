NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra
#SEG = -fsanitize=address -g

PRINT_PATH = ./print/
SRC_PATH = ./srcs/
LBFT_PATH = ./libft/
OBJ_DIR = ./obj/

PRINT =	print_push \
		print_reverse \
		print_rotate \
		print_swap		

SRC =	error \
		lst_make_a \
		lst_make_b \
		lst_move \
		lst_sort \
		opperator \
		push_swap \
		utils \
		utils2

LBFT = 	ft_atol \
		ft_split \
		ft_strchr \
		ft_strlen  


C_FILES = $(addprefix $(PRINT_PATH), $(PRINT:=.c)) $(addprefix $(SRC_PATH), $(SRC:=.c)) $(addprefix $(LBFT_PATH), $(LBFT:=.c))
OBJ = $(addprefix $(OBJ_DIR), $(PRINT:=.o)) $(addprefix $(OBJ_DIR), $(SRC:=.o)) $(addprefix $(OBJ_DIR), $(LBFT:=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(PRINT_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(LBFT_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



