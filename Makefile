
NAME = so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror -g


SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libs/libft
MLX42_DIR = libs/MLX42


MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -I$(MLX42_DIR)/include -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lpthread -lm
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -I$(LIBFT_DIR)


SRC = src/main.c
OBJ = $(OBJ_DIR)/main.o

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(MLX42_FLAGS) $(LIBFT_LIB) -o $(NAME)


$(OBJ_DIR)/main.o: $(SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(LIBFT_FLAGS) -I$(MLX42_DIR)/include -c $< -o $@


$(LIBFT_LIB):
	make -C $(LIBFT_DIR)


clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re