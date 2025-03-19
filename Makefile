
NAME = so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = libs
MLX42_DIR = $(LIB_DIR)/MLX42
LIBFT_DIR = $(LIB_DIR)/libft

SRC_FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -I$(MLX42_DIR)/include -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lpthread -lm
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(MLX42_FLAGS) $(LIBFT_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(LIBFT_FLAGS) -I$(MLX42_DIR)/include -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
